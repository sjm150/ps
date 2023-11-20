#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll cnt = 0;
        int nxt = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > nxt) {
                int r = a[i] % nxt;
                if (r) {
                    int d = a[i] / nxt + 1;
                    cnt += d - 1;
                    nxt = a[i] / d;
                } else {
                    cnt += a[i] / nxt - 1;
                }
            } else {
                nxt = a[i];
            }
        }

        cout << cnt << '\n';
    }
}