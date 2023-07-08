#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> edges;
bool vst[1000];

void dfs(int curr) {
    vst[curr] = true;
    for (int next: edges[curr]) {
        if (!vst[next]) dfs(next);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    edges = vector<vector<int>>(n);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        edges[from - 1].push_back(to - 1);
        edges[to - 1].push_back(from - 1);
    }
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (!vst[i]) {
            dfs(i);
            num++;
        }
    }
    cout << num << '\n';
}