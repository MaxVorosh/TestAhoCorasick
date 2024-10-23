#ifndef TESTAHOCORASICK_AC_H
#define TESTAHOCORASICK_AC_H

#include <string>
#include <vector>

struct Vertex {
    int next[26];
    bool leaf;
    int p;
    char pch;
    int link;
    int go[26];
    bool suff_go;
    int ind;

    Vertex();
};


class AhoCorasick {
private:
    std::vector<Vertex> bor;
    std::vector<bool> dict;
public:

    AhoCorasick();
    void add_string(std::string& s, int ind);
    int get_link(int v);
    int go(int v, char c);
    void suff_go(int v);
    bool visited(int i);
};


#endif