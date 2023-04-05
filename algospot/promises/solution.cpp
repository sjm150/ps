#include <iostream>
#include <vector>

#define INF 123456789

using namespace std;

void floyd(vector<vector<int>>& dists);
bool update_dists(vector<vector<int>>& dists, int from, int to, int weight);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        int v, m, n;
        cin >> v >> m >> n;
        vector<vector<int>> dists(v, vector<int>(v, INF));
        for (int i = 0; i < m; i++) {
            int from, to, weight;
            cin >> from >> to >> weight;
            dists[from][to] = dists[to][from] = min(dists[from][to], weight);
        }
        for (int i = 0; i < v; i++) dists[i][i] = 0;

        floyd(dists);

        int useless = 0;
        for (int i = 0; i < n; i++) {
            int from, to, weight;
            cin >> from >> to >> weight;
            if (!update_dists(dists, from, to, weight)) useless++;
        }

        cout << useless << endl;
    }
}

void floyd(vector<vector<int>>& dists) {
    int v = dists.size();
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
            }
        }
    }
}

bool update_dists(vector<vector<int>>& dists, int from, int to, int weight) {
    if (dists[from][to] <= weight) return false;

    int v = dists.size();
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            dists[i][j] = min(dists[i][j], min(dists[i][from] + weight + dists[to][j], dists[i][to] + weight + dists[from][j]));
        }
    }
    return true;
}