#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int n, m, h;
vector<vector<bool>> conn;
vector<pi> cand;

bool simul() {
    for (int j = 1; j <= n; j++) {
        int cur = j;
        for (int i = 1; i <= h; i++) {
            if (conn[i][cur - 1]) cur--;
            else if (conn[i][cur]) cur++;
        }
        if (cur != j) return false;
    }
    return true;
}

int next_cand(int i) {
    if (i >= cand.size() - 1) return cand.size();
    if (cand[i].first == cand[i + 1].first && cand[i].second + 1 == cand[i + 1].second) return i + 2;
    else return i + 1;
}

int solve() {
    if (simul()) return 0;
    int ans = 4;
    for (int i = 0; i < cand.size(); i++) {
        conn[cand[i].first][cand[i].second] = true;
        if (simul() && ans > 1) ans = 1;
        for (int j = next_cand(i); j < cand.size(); j++) {
            conn[cand[j].first][cand[j].second] = true;
            if (simul() && ans > 2) ans = 2;
            for (int k = next_cand(j); k < cand.size(); k++) {
                conn[cand[k].first][cand[k].second] = true;
                if (simul() && ans > 3) ans = 3;
                conn[cand[k].first][cand[k].second] = false;
            }
            conn[cand[j].first][cand[j].second] = false;
        }
        conn[cand[i].first][cand[i].second] = false;
    }
    if (ans > 3) return -1;
    else return ans;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m >> h;
    conn.resize(h + 1, vector<bool>(n + 1, false));
    while (m--) {
        int a, b; cin >> a >> b;
        conn[a][b] = true;
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j < n; j++) {
            if (!conn[i][j - 1] && !conn[i][j] && !conn[i][j + 1]) cand.emplace_back(i, j);
        }
    }
    cout << solve() << '\n';
}