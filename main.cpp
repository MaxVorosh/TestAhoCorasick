#include <bits/stdc++.h>
#include "AC.h"

using namespace std;

const int Inf = 2e9;

Vertex::Vertex() {
    fill(next, next + 26, -1);
    fill(go, go + 26, -1);
    leaf = false;
    p = -1;
    pch = -1;
    link = -1;
    suff_go = false;
    ind = -1;
}


AhoCorasick::AhoCorasick() {
    bor.push_back(Vertex());
}

void AhoCorasick::add_string(string& s, int ind) {
    int v = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (bor[v].next[s[i] - 'a'] == -1) {
            bor.push_back(Vertex());
            bor.back().p = v;
            bor.back().pch = s[i];
            bor[v].next[s[i] - 'a'] = bor.size() - 1;
        }
        v = bor[v].next[s[i] - 'a'];
    }
    bor[v].leaf = true;
    bor[v].ind = ind;
    dict.push_back(false);
}

int AhoCorasick::get_link(int v) {
    if (bor[v].link == -1) {
        if (v == 0 || bor[v].p == 0) {
            bor[v].link = 0;
        }
        else {
            bor[v].link = go(get_link(bor[v].p), bor[v].pch - 'a');
        }
    }
    return bor[v].link;
}

int AhoCorasick::go(int v, char c) {
    if (bor[v].go[c] == -1) {
        if (bor[v].next[c] != -1) {
            bor[v].go[c] = bor[v].next[c];
        }
        else if (v == 0) {
            bor[v].go[c] = 0;
        }
        else {
            bor[v].go[c] = go(get_link(v), c);
        }
    }
    return bor[v].go[c];
}

void AhoCorasick::suff_go(int v) {
    if (bor[v].suff_go) {
        return;
    }
    bor[v].suff_go = true;
    if (bor[v].leaf) {
        dict[bor[v].ind] = true;
    }
    if (v != 0) {
        suff_go(get_link(v));
    }
}

bool AhoCorasick::visited(int i) {
    return dict[i];
}