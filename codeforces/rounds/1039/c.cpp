#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int &b: b) cin >> b;

        auto solve = [&]() {
            int mn = b[0];
            for (int b: b) {
                if (b >= mn * 2) return false;
                mn = min(mn, b);
            }
            return true;
        };

        cout << (solve() ? "YES\n" : "NO\n");
    }
}