#include <bits/stdc++.h>

using namespace std;

const int Inf = 2e9;

struct Vertex {
    int next[26];
    bool leaf;
    int p;
    char pch;
    int link;
    int go[26];
    bool suff_go;
    int ind;

    Vertex() {
        fill(next, next + 26, -1);
        fill(go, go + 26, -1);
        leaf = false;
        p = -1;
        pch = -1;
        link = -1;
        suff_go = false;
        ind = -1;
    }
};

class AhoCorasick {
private:
    vector<Vertex> bor;
    vector<bool> dict;
public:

    AhoCorasick() {
        bor.push_back(Vertex());
    }

    void add_string(string& s, int ind) {
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

    int get_link(int v) {
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

    int go(int v, char c) {
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

    void suff_go(int v) {
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

    bool visited(int i) {
        return dict[i];
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    AhoCorasick AC;
    string data[] = {"abacabadabacaba", "olo", "trol", "", "trolololo", "t", "troglodit", "trololo"};
    bool results[] = {false, true, true, true, false, true, false, true};
    string t = "trololo";
    int k = 8;
    for (int i = 0; i < k; ++i) {
        string s = data[i];
        AC.add_string(s, i);
    }
    int v = 0;
    for (int i = 0; i < t.size(); ++i) {
        v = AC.go(v, t[i] - 'a');
        AC.suff_go(v);
    }
    for (int i = 0; i < k; ++i) {
        assert(AC.visited(i) == results[i]);
    }
    return 0;
}