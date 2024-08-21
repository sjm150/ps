#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> edges;
        set<int> r;
        for (int i = 2; i <= n; i++) r.insert(i);
        while (!r.empty()) {
            int a = 1, b = *r.begin();
            for (;;) {
                cout << "? " << a << ' ' << b << endl;
                int x; cin >> x;
                if (x < 0) return 1;
                if (x == a || x == b) {
                    edges.emplace_back(a, b);
                    r.erase(b);
                    break;
                } else if (r.find(x) == r.end()) {
                    a = x;
                } else {
                    b = x;
                }
            }
        }
        cout << '!';
        for (auto &[a, b]: edges) cout << ' ' << a << ' ' << b;
        cout << endl;
    }
}