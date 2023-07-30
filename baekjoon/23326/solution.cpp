#include <iostream>
#include <set>
typedef long long lint;
using namespace std;

set<int> attr;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == 1) attr.insert(i);
    }
    int cur = 0;
    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int i; cin >> i;
            i--;
            auto it = attr.find(i);
            if (it == attr.end()) attr.insert(i);
            else attr.erase(it);
        } else if (cmd == 2) {
            int x; cin >> x;
            cur = (cur + x) % n;
        } else {
            if (attr.empty()) {
                cout << -1 << '\n';
                continue;
            }
            auto it = attr.lower_bound(cur);
            int move;
            if (it != attr.end()) move = *it - cur;
            else move = *attr.lower_bound(0) + n - cur;
            cout << move << '\n';
        }
    }
}