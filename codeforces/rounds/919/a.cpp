#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        set<int> neq;
        int lo = 1, hi = 1e9;
        while (n--) {
            int a, x; cin >> a >> x;
            if (a == 1) lo = max(lo, x);
            else if (a == 2) hi = min(hi, x);
            else neq.insert(x);
        }

        for (auto it = neq.begin(); it != neq.end();) {
            if (*it < lo || hi < *it) it = neq.erase(it);
            else it++;
        }
        cout << max(0, hi - lo + 1 - int(neq.size())) << '\n';
    }
}