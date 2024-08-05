#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        vector<int> aa = a;
        sort(aa.begin(), aa.end());

        int sz = n % k;
        if (sz == 0) sz = k;
        int l = 0, r = n;
        while (l < r) {
            int m = (l + r) / 2;
            vector<int> cnt(sz, 0);
            for (int i = 0; i < n; i++) {
                int rem = i % k;
                if (rem >= sz) continue;
                cnt[rem] = max(cnt[rem], (rem ? cnt[rem - 1] : 0) + (a[i] >= aa[m]));
            }
            if (cnt[sz - 1] * 2 > sz) l = m + 1;
            else r = m;
        }

        cout << aa[r - 1] << '\n';
    }
}