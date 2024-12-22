#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> ans(n, 0);
        int cur = 1;
        for (int i = k - 1; i < n; i += k) ans[i] = cur++;
        for (int i = 0; i < n; i++) {
            if (!ans[i]) ans[i] = cur++;
        }
        for (int a: ans) cout << a << ' ';
        cout << '\n';
    }
}