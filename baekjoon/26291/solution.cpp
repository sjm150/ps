#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;

    bool ok = true;
    vector<pair<int, int>> ans;
    if (k == 1) {
        for (int i = 1; i < n; i++) ans.emplace_back(i, i + 1);
        if (n > 2) ans.emplace_back(n, 1);
    } else if (k < n) {
        for (int i = 1; i < k - i + 2; i++) {
            for (int j = i; j < k - i + 2; j++) ans.emplace_back(j, k - i + 2);
        }
        if (k < n - 1) {
            ans.emplace_back(1, k + 2);
            for (int i = k + 2; i < n; i++) ans.emplace_back(i, i + 1);
        }
    } else {
        ok = false;
    }

    if (ok) {
        cout << "YES\n";
        cout << ans.size() << '\n';
        for (auto [a, b]: ans) cout << a << ' ' << b << '\n';
    } else {
        cout << "NO\n";
    }
}