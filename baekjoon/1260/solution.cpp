#include <iostream>
#include <queue>

using namespace std;

int n, m, v;
bool edge[1000][1000];
bool vst[1000];

void dfs(int curr) {
    cout << curr + 1 << ' ';
    vst[curr] = true;
    for (int next = 0; next < n; next++) {
        if (edge[curr][next] && !vst[next]) {
            dfs(next);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        edge[from - 1][to - 1] = edge[to - 1][from - 1] = true;
    }
    dfs(v - 1);
    cout << '\n';
    for (int i = 0; i < n; i++) vst[i] = false;
    queue<int> q;
    q.push(v - 1);
    vst[v - 1] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr + 1 << ' ';
        for (int next = 0; next < n; next++) {
            if (edge[curr][next] && !vst[next]) {
                q.push(next);
                vst[next] = true;
            }
        }
    }
    cout << '\n';
}