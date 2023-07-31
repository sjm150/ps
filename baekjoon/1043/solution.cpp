#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edges;
vector<bool> ack;
void dfs(int cur) {
    ack[cur] = true;
    for (int nxt: edges[cur]) {
        if (!ack[nxt]) dfs(nxt);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    edges = vector<vector<int>>(n + 1);
    ack = vector<bool>(n + 1, false);
    int k; cin >> k;
    vector<int> ini(k);
    for (int i = 0; i < k; i++) cin >> ini[i];
    vector<vector<int>> party(m + 1);
    for (int p = 1; p <= m; p++) {
        cin >> k;
        party[p] = vector<int>(k);
        for (int i = 0; i < k; i++) cin >> party[p][i];
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                edges[party[p][i]].push_back(party[p][j]);
                edges[party[p][j]].push_back(party[p][i]);
            }
        }
    }
    for (int i: ini) {
        if (!ack[i]) dfs(i);
    }
    int cnt = 0;
    for (int p = 1; p <= m; p++) {
        bool able = true;
        for (int i: party[p]) {
            if (ack[i]) {
                able = false;
                break;
            }
        }
        if (able) cnt++;
    }
    cout << cnt << '\n';
}