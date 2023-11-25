#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> c(n);
        for (int i = 0; i < n; i++) cin >> c[i];
        long long cnt = c[n - 1] - 1;
        for (int i = 1; i < n; i++) {
            if (c[i - 1] > c[i]) cnt += c[i - 1] - c[i];
        }
        cout << cnt << '\n';
    }
}