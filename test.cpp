#include "bits/stdc++.h"
#include "AC.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    AhoCorasick AC;
    string data[] = {"olo", "trol",  "trolololo"};
    bool results[] = {true, true, false};
    string t = "trololo";
    int k = 3;
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
    // get_link addition test
    AhoCorasick link_AC;
    assert(link_AC.get_link(0) == 0);
    return 0;
}