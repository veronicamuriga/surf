//
// Created by kliment on 12/3/21.
//

#ifndef SURF_SURF_IMPLEMENTATION_H
#define SURF_SURF_IMPLEMENTATION_H

#include <string>

using namespace std;


bool contains(const vector<string>& dataset, string left, string right);

int surf_main();

class SurfStats
{
    int trie_size;
    double bits_per_key;
    double fpr;

public:

    SurfStats(int _trie_size, double _bits_per_key, double _fpr): trie_size(_trie_size), bits_per_key(_bits_per_key), fpr(_fpr)
    {

    }

    string to_string() const {
        return "trie_size\t" + std::to_string(trie_size) + "\tbits_per_key\t" + std::to_string(bits_per_key) + "\tfalse_positive_rate(%)\t"+std::to_string(fpr);
    }
};

SurfStats test_surf(vector<string>& dataset, vector<pair<string, string> >& workload, int trie_size);

#endif //SURF_SURF_IMPLEMENTATION_H
