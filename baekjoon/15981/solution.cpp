#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int sz = int(log2(n)) + 2;
    vector<vector<int>> ans(sz);
    for (int i = 1; i <= n; i++) {
        for (int b = 0; b < sz; b++) {
            if (i & (1 << b)) ans[b].push_back(i);
        }
    }
    while (ans.back().size() <= 1) ans.pop_back();
    cout << ans.size() << '\n';
    for (auto &ans: ans) {
        cout << ans.size() << ' ';
        for (int a: ans) cout << a << ' ';
        cout << '\n';
    }
}