#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, c; cin >> n >> c;
        vector<int> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];

        ll cnt = ll(c + 1) * (c + 2) / 2;
        int o = 0, e = 0;
        for (int s: s) {
            if (s & 1) {
                cnt -= s / 2 + c - s + 1 - o;
                o++;
            } else {
                cnt -= s / 2 + c - s + 1 - e;
                e++;
            }
        }

        cout << cnt << '\n';
    }
}