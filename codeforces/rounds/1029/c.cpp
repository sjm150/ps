#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        map<int, int> idx;
        vector<int> nxt(n, n);
        for (int i = n - 1; i >= 0; i--) {
            auto it = idx.find(a[i]);
            if (it != idx.end()) nxt[i] = it->second;
            idx[a[i]] = i;
        }

        int l = 0, r = 0, ans = 1;
        for (;; ans++) {
            int mx = r;
            for (int i = l; i <= r; i++) mx = max(mx, nxt[i]);
            if (mx >= n) break;
            l = r + 1;
            r = mx;
        }
        cout << ans << '\n';
    }
}