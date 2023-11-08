#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), cnt(101, 0), lst(101, -1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
            lst[a[i]] = i;
        }
        vector<int> ans(n, 1);
        int nxt = 2;
        for (int i = 1; i <= 100; i++) {
            if (cnt[i] >= 2) {
                ans[lst[i]] = nxt++;
                if (nxt > 3) break;
            }
        }
        if (nxt > 3) {
            for (int a: ans) cout << a << ' ';
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}