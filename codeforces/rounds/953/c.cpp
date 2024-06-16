#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);

        if (k % 2) {
            cout << "No\n";
            continue;
        }
        for (int l = 0, r = n - 1; k && l < r; l++) {
            while (l < r && 2 * (p[r] - p[l]) > k) r--;
            if (l < r) {
                k -= 2 * (p[r] - p[l]);
                swap(p[l], p[r--]);
            }
        }

        if (k) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for (int p: p) cout << p << ' ';
            cout << '\n';
        }
    }
}