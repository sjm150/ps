#include <iostream>
#include <set>
typedef long long lint;
using namespace std;

set<int> lset;
set<int> pofls[101];
int lofp[100001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    while (n--) {
        int p, l; cin >> p >> l;
        lset.insert(l);
        pofls[l].insert(p);
        lofp[p] = l;
    }
    int m; cin >> m;
    while (m--) {
        string cmd; cin >> cmd;
        if (cmd == "recommend") {
            int x; cin >> x;
            if (x == 1) cout << *prev(pofls[*prev(lset.end())].end()) << '\n';
            else cout << *pofls[*lset.begin()].begin() << '\n';
        } else if (cmd == "add") {
            int p, l; cin >> p >> l;
            lset.insert(l);
            pofls[l].insert(p);
            lofp[p] = l;
        } else {
            int p; cin >> p;
            pofls[lofp[p]].erase(p);
            if (pofls[lofp[p]].empty()) lset.erase(lofp[p]);
            lofp[p] = 0;
        }
    }
}