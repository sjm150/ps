#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

pi ds[100];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> ds[i].first >> ds[i].second;
        sort(ds, ds + n);
        int k = 1000;
        for (int i = 0; i < n; i++) {
            if (ds[i].first > k) break;
            k = min(k, ds[i].first + (ds[i].second - 1) / 2);
        }
        cout << k << '\n';
    }
}