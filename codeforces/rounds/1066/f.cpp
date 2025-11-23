#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    if (n == 4) {
        for (int i = 1; i < 4; i++) ans.emplace_back(i, 1);
    } else {
        const int mx = 250000;
        for (int i = mx - 100 + 1; i < mx; i++) {
            for (int j = i; j > 0; j -= 100) ans.emplace_back(j, 1);
        }
        for (int i = mx - 10000 + 100; i < mx; i += 100) {
            for (int j = i; j > 0; j -= 10000) ans.emplace_back(j, 100);
        }
        for (int i = 10000; i < mx; i += 10000) ans.emplace_back(i, 10000);
    }
    cout << ans.size() << '\n';
    for (auto [y, l]: ans) cout << y << ' ' << l << '\n';
}