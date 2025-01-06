#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<bool> vst(n + 1, false);
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++) {
        if (vst[i] || p[i] == i) continue;
        vst[i] = true;
        ans.emplace_back();
        auto &o = ans.back();
        o.push_back(i);
        for (int j = p[i]; j != i; j = p[j]) {
            vst[j] = true;
            o.push_back(j);
        }
    }
    if (ans.size() > 2) {
        cout << 2 << '\n';
        int sz = ans.size(), pre = p[ans.back()[0]];
        cout << sz << ": ";
        for (int i = 0; i < sz; i++) {
            cout << ans[i][0] << ' ';
            swap(pre, p[ans[i][0]]);
        }
        cout << '\n';
        int cnt = 0;
        for (auto &a: ans) cnt += a.size();
        cout << cnt << ": ";
        for (int i = 0; i < n; i++) {
            if (p[i] == i) continue;
            cout << i << ' ';
            for (int j = p[i]; j != i; j = p[j]) cout << j << ' ';
            cout << '\n';
            break;
        }
    } else {
        cout << ans.size() << '\n';
        for (auto &a: ans) {
            cout << a.size() << ": ";
            for (int a: a) cout << a << ' ';
            cout << '\n';
        }
    }
}