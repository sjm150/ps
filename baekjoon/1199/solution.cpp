#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for (auto &a: adj) {
        for (int &a: a) cin >> a;
    }

    bool ok = true;
    for (auto &a: adj) {
        if (accumulate(a.begin(), a.end(), 0) % 2) {
            ok = false;
            break;
        }
    }

    if (ok) {
        vector<int> idx(n, 0), ans;
        function<void(int)> dfs = [&](int cur) {
            while (idx[cur] < n) {
                if (adj[cur][idx[cur]]) {
                    adj[cur][idx[cur]]--;
                    adj[idx[cur]][cur]--;
                    dfs(idx[cur]);
                } else {
                    idx[cur]++;
                }
            }
            ans.push_back(cur);
        };
        dfs(0);
        for (int a: ans) cout << a + 1 << ' ';
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}