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
    double fnr;

public:

    SurfStats(int _trie_size, double _bits_per_key, double _fpr, double _fnr): trie_size(_trie_size), bits_per_key(_bits_per_key), fpr(_fpr), fnr(_fnr)
    {

    }

    string to_string() const {
        return "trie_size\t" + std::to_string(trie_size) + "\tbpk\t" + std::to_string(bits_per_key) + "\tfpr\t"+std::to_string(fpr)+ "\tfng\t"+std::to_string(fnr);
    }
};

SurfStats test_surf(const vector<string>& dataset, const vector<pair<string, string> >& workload, int trie_size);

#endif //SURF_SURF_IMPLEMENTATION_H
