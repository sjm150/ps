#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int x, n; cin >> x >> n;

        vector<int> d;
        for (long long i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                d.push_back(i);
                d.push_back(x / i);
            }
        }
        sort(d.begin(), d.end());

        cout << x / *lower_bound(d.begin(), d.end(), n) << '\n';
    }
}