//
// Created by kliment on 12/3/21.
//

#ifndef SURF_SURF_IMPLEMENTATION_H
#define SURF_SURF_IMPLEMENTATION_H

#include <string>

using namespace std;

class RangeFilterStats
{
public:
    int input_size;
    float seed_fpr;
    int num_keys;
    int num_queries;
    int num_false_positives;
    int num_negatives;
    unsigned long long total_num_bits;
    RangeFilterStats(
            int _input_size,
            float _seed_fpr,
            int _num_keys,
            int _num_queries,
            int _num_false_positives,
            int _num_negatives,
            unsigned long long _total_num_bits):
            input_size(_input_size),
            seed_fpr(_seed_fpr),
            num_keys(_num_keys),
            num_queries(_num_queries),
            num_false_positives(_num_false_positives),
            num_negatives(_num_negatives),
            total_num_bits(_total_num_bits){}

    string to_string() {
        string ret;
        ret += "size\t"+std::to_string(input_size)+"\tseed_fpr\t"+std::to_string(seed_fpr)+"\tbits_per_key\t"+std::to_string(bits_per_key())+"\tfalse_positive_rate\t"+std::to_string(false_positive_rate());
        return ret;
    }

    double false_positive_rate() const
    {
        return (double)num_false_positives/num_negatives*100.0;
    }

    double bits_per_key()
    {
        return ((double)total_num_bits / num_keys);
    }
};


bool contains(const vector<string>& dataset, string left, string right);

int surf_main();

RangeFilterStats test_surf(vector<string>& dataset, vector<pair<string, string> >& workload, int trie_size);

#endif //SURF_SURF_IMPLEMENTATION_H
