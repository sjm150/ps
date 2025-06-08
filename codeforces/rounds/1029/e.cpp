#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &a: a) cin >> a;
        for (int &b: b) cin >> b;

        int mx = max(*max_element(a.begin(), a.end()), *max_element(b.begin(), b.end()));
        vector<int> occ(mx + 1, false);

        auto solve = [&]() {
            for (int i = n - 1; i >= 0; i--) {
                if (a[i] == b[i]) return i;
                if (i < n - 1) {
                    if (a[i] == a[i + 1] || b[i] == b[i + 1] || occ[a[i]] || occ[b[i]]) return i;
                    occ[a[i + 1]] = occ[b[i + 1]] = true;
                }
            }
            return -1;
        };

        cout << solve() + 1 << '\n';
    }
}