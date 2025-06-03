#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        multiset<int> ba, ca, bc, cb;
        for (int i = 0; i < q; i++) {
            string xy = "  ";
            cin >> xy[0] >> xy[1];
            if (xy == "ba") ba.insert(i);
            else if (xy == "ca") ca.insert(i);
            else if (xy == "bc") bc.insert(i);
            else if (xy == "cb") cb.insert(i);
        }

        for (char &c: s) {
            if (c == 'b') {
                if (!ba.empty()) {
                    ba.erase(ba.begin());
                    c = 'a';
                } else if (!bc.empty() && !ca.empty()) {
                    auto it = ca.lower_bound(*bc.begin());
                    if (it != ca.end()) {
                        bc.erase(bc.begin());
                        ca.erase(it);
                        c = 'a';
                    }
                }
            } else if (c == 'c') {
                if (!ca.empty()) {
                    ca.erase(ca.begin());
                    c = 'a';
                } else if (!cb.empty() && !ba.empty()) {
                    auto it = ba.lower_bound(*cb.begin());
                    if (it != ba.end()) {
                        cb.erase(cb.begin());
                        ba.erase(it);
                        c = 'a';
                    }
                }
                if (c == 'c' && !cb.empty()) {
                    cb.erase(prev(cb.end()));
                    c = 'b';
                }
            }
        }

        cout << s << '\n';
    }
}