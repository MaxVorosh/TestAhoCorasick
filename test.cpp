#include "bits/stdc++.h"
#include "AC.h"

using namespace std;

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