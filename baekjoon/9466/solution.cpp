#include <iostream>

using namespace std;

int n;
int edge[100000];
int visit[100000];
int group[100000];

int dfs(int id, int v) {
    visit[id] = v;
    int next = edge[id];
    if (visit[next] == -1) {
        group[id] = dfs(next, v);
    } else if (visit[next] == v) {
        group[id] = next;
    }
    if (group[id] == id) return -1;
    return group[id];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int to;
            cin >> to;
            edge[i] = to - 1;
            visit[i] = -1;
            group[i] = -1;
        }

        int visit_id = 0;
        for (int i = 0; i < n; i++) {
            if (visit[i] == -1) dfs(i, visit_id++);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) count++;
        }
        cout << count << '\n';
    }
}