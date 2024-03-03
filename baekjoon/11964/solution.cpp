#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t, a, b; cin >> t >> a >> b;

    vector<vector<bool>> ful(2, vector<bool>(t + 1, false));
    queue<pair<int, int>> q;
    ful[0][0] = true;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [drk, cur] = q.front(); q.pop();
        if (!drk && !ful[0][cur / 2]) {
            ful[1][cur / 2] = true;
            q.emplace(1, cur / 2);
        }
        int nxts[2] = {cur + a, cur + b};
        for (int nxt: nxts) {
            if (nxt <= t && !ful[drk][nxt]) {
                ful[drk][nxt] = true;
                q.emplace(drk, nxt);
            }
        }
    }
    
    for (int i = t; i; i--) {
        if (ful[0][i] || ful[1][i]) {
            cout << i << '\n';
            break;
        }
    }
}