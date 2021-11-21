#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "include/surf.hpp"

using namespace surf;
using namespace std;

int surf_implementation(double fpr, uint64_t space) {

    std::vector<std::string> keys;

	std::vector<std::string> datasets;
	std::vector<std::string> workloads;

	string item_name;
	ifstream nameFileout;
	// nameFileout.open("datasets/url_data_set.txt");
	nameFileout.open("datasets/emails-validated-random-only-30-characters.txt.sorted");
	string line;
	while(std::getline(nameFileout, line))
	{
		keys.push_back(line); // save key for now
		// std::cout << "line:" << line << std::endl;
		// decide at random whether to put it in dataset or workload
		// TODO: can i be sure that exactly half of the dataset is in each vector, or should i enforce size checks
		double r = rand()/RAND_MAX;
		if (r > 0.5){
			datasets.push_back(line);
			//TODO: i can actually incorporate left_key, right_key logic here to save on runtime caused by another iteration
		} else {
			workloads.push_back(line);
		}
	}


	// basic surf
	SuRF* surf = new SuRF(datasets);

	// SuRF* surf_real = new SuRF(keys, surf::kReal, 0, 8);

	//----------------------------------------
	// range queries
	//----------------------------------------
	std::cout << "\nRange Query Example: [fare, fase)" << std::endl;
	
	/* generate left and right keys according to SuRF workload implementation:
	- draw a key from workload half of dataset at random
	- range query is [K, K(with last byte ++)]	
	*/

	std::vector<std::string> left_keys;
	std::vector<std::string> right_keys;

	// double fpr = 0;
	uint64_t fp = 0;
	uint64_t tn = 0;

	// for storing fpr and space metrics
	// fpr = (fp / (fp + tn)) where fp = number of false positives and tn = number of true negatives
	// how to calculate space?

	for (int i = 0; i < (int) keys.size()/2; i++){
		string left_key = workloads[rand() % workloads.size()];
		string right_key = left_key + left_key[left_key.length() - 1];	
		left_keys.push_back(left_key);
		right_keys.push_back(right_key);

		if (surf->lookupRange(left_key, true, right_key, false)){
			fp += 1;
			std::cout << "False Positive: There exist key(s) within range ["
				<< left_key << ", " << right_key << ") " << "according to basic SuRF" << std::endl;
		} else { 
			tn += 1;
			std::cout << "Correct: No key exists within range ["
				<< left_key << ", " << right_key << ") " << "according to basic SuRF" << std::endl;
		}
	}

	fpr = fp / (fp + tn);
	space = surf->getMemoryUsage();
	return 0;

}


int main(){
	int NITER = 10;
	vector<double> fpr_vec;
	vector<uint64_t> space_vec;

	double fpr = 0;
	uint64_t space = 0;

	for (int i = 0; i < NITER; i ++){ // TODO: test with NITER = 1000000
		fpr = 0;
		space = 0;
		
		surf_implementation(fpr, space);

		fpr_vec.push_back(fpr);
		space_vec.push_back(space);
	}

	// TODO: plot fpr vs memory usage

	return 0;
}



// // TODO: basic surf or surf real?
// if (surf->lookupRange(left_key, true, right_key, false))
// std::cout << "False Positive: There exist key(s) within range ["
// 	  << left_key << ", " << right_key << ") " << "according to basic SuRF" << std::endl;
// else
// std::cout << "Correct: No key exists within range ["
// 	  << left_key << ", " << right_key << ") " << "according to basic SuRF" << std::endl;

// if (surf_real->lookupRange(left_key, true, right_key, false))
// std::cout << "False Positive: There exist key(s) within range ["
// 	  << left_key << ", " << right_key << ") " << "according to SuRF real" << std::endl;
// else
// std::cout << "Correct: No key exists within range ["
// 	  << left_key << ", " << right_key << ") " << "according to SuRF real" << std::endl;