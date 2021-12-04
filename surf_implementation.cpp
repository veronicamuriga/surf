#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include "include/surf.hpp"

using namespace surf;
using namespace std;

int NITER = 8;
vector<double> fpr_vec;
vector<uint64_t> space_vec;

double fpr = 0;
uint64_t space = 0;
level_t trie_size = 0;


std::vector<std::string> keys;
std::vector<std::string> datasets;
std::vector<std::string> workloads;
uint64_t WORKLOAD_SIZE = 1000000;

int query_binary_search(string left_key, string right_key){

	int i = 0;
	while (left_key[i] == right_key[i]){
		// if dataset does not contain a common prefix, retuurn false
		if(!binary_search(keys.begin(), keys.end(), left_key.substr(0, i + 1))){
			return 0;
		}
		i += 1;

	}

	// gotten past common substring;
	// query left_key[i] .... right_key[i] on BF
	// edge case: BF for a certain index doesn't exist
	// bounds checking: make sure right_key[i] is within the a-z || A-Z bounds
	for (char ch = left_key[i]; ch < right_key[i] + 1; ch++){
		if (binary_search(keys.begin(), keys.end(),left_key.substr(0, i) + ch)){
			return 1;
		}
	}
    return 0;
}

int surf_implementation() {


	// use real surf with given number of bits 
	SuRF* surf_real = new SuRF(datasets, surf::kReal, 0, trie_size);

	//----------------------------------------
	// range queries
	//----------------------------------------
	
	/* generate left and right keys according to SuRF workload implementation:
	- draw a key from workload half of dataset at random
	- range query is [K, K(with last byte ++)]	
	*/

	std::vector<std::string> left_keys;
	std::vector<std::string> right_keys;

	// double fpr = 0;
	uint64_t fp = 0;
	uint64_t tn = 0;
	string right_key;
	string left_key;

	// for storing fpr and space metrics
	// fpr = (fp / (fp + tn)) where fp = number of false positives and tn = number of true negatives
	// how to calculate space?

	for (uint64_t i = 0; i < WORKLOAD_SIZE; i++){
        int r = rand();
        int id = r % workloads.size();
		left_key = workloads[id];
		right_key = left_key;
		right_key[right_key.length() - 1]++;	

		left_keys.push_back(left_key);
		right_keys.push_back(right_key);

		int binary_search_result = query_binary_search(left_key, right_key);
		bool surf_result = surf_real->lookupRange(left_key, true, right_key, false);


		if (surf_result && (binary_search_result == 0)){
			// false positive
			fp += 1;
			// std::cout << "False Positive: There exist key(s) within range ["
			// 	<< left_key << ", " << right_key << ") " << "according to real SuRF" << std::endl;
		} else if ((surf_result == false) && (binary_search_result == 0)){ 
			// true negative
			tn += 1;
			// std::cout << "Correct: No key exists within range ["
			// 	<< left_key << ", " << right_key << ") " << "according to real SuRF" << std::endl;
		}
	}

	fpr = (fp * 1.0)/ (fp + tn);
	space = surf_real->getMemoryUsage();
	cout<<"fpr: "<<fpr<<" and space: "<<space<<endl;

	return 0;

}


int surf_main(){

	string item_name;
	ifstream nameFileout;
	nameFileout.open("/home/sparklab/RangeFilter/data/small_data_dataset.txt");
	string line;
	while(std::getline(nameFileout, line))
	{
		keys.push_back(line); // save key for now
		datasets.push_back(line);
		
	}
	nameFileout.close();

	nameFileout.open("/home/sparklab/RangeFilter/data/small_data_workload.txt");
	while(std::getline(nameFileout, line))
	{
		keys.push_back(line); // save key for now
		workloads.push_back(line);
		
	}
	nameFileout.close();

	for (int i = 0; i < NITER; i ++){ // TODO: test with 1000000
		trie_size += 8;
		fpr = 0;
		space = 0;
		
		surf_implementation();

		fpr_vec.push_back(fpr);
		space_vec.push_back(space);
	
	}

	// TODO: plot fpr vs memory usage

	return 0;
}
