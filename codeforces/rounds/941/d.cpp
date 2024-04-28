#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> ans;
        for (int i = 1; i <= n; i *= 2) ans.push_back(i);

        int idx = upper_bound(ans.begin(), ans.end(), k) - ans.begin() - 1;
        ans.push_back(k - ans[idx]);
        ans.push_back(ans[idx] * 3);
        ans[idx] = k + 1;

        cout << ans.size() << '\n';
        for (int a: ans) cout << a << ' ';
        cout << '\n';
    }
}