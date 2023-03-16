#include <iostream>
#include <vector>

using namespace std;

int g, h;
vector<vector<int>> adj;

int cover_number();

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        cin >> g >> h;
        adj = vector<vector<int>>(g, vector<int>());
        for (int i = 0; i < h; i++) {
            int g1, g2;
            cin >> g1 >> g2;
            adj[g1].push_back(g2);
            adj[g2].push_back(g1);
        }

        cout << cover_number() << endl;
    }
}

vector<bool> visited;
vector<bool> covered;

int cover_dfs(int curr) {
    int sum = 0;
    bool should_cover = false;

    visited[curr] = true;

    for (int next: adj[curr]) {
        if (!visited[next]){
            sum += cover_dfs(next);
            if (!covered[next]) should_cover = true;
        }
    }

    if (should_cover) {
        sum++;
        covered[curr] = true;
        for (int next: adj[curr]) covered[next] = true;
    }

    return sum;
}

int cover_number() {
    int sum = 0;
    visited = covered = vector<bool>(g, false);
    for (int i = 0; i < g; i++) {
        if (!visited[i]) {
            sum += cover_dfs(i);
            if (!covered[i]) {
                sum++;
                covered[i] = true;
            }
        }
    }

    return sum;
}