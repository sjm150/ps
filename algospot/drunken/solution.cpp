#include <iostream>
#include <vector>
#include <algorithm>

#define INF 5000000

using namespace std;

vector<vector<int>> floyd(vector<int>& times, vector<vector<int>>& dists);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int v, e;
    cin >> v >> e;

    vector<int> times(v);
    vector<vector<int>> dists(v, vector<int>(v, INF));

    for (int i = 0; i < v; i++) cin >> times[i];
    for (int i = 0; i < e; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        dists[from - 1][to - 1] = dists[to - 1][from - 1] = weight;
    }
    for (int i = 0; i < v; i++) dists[i][i] = 0;

    auto worst = floyd(times, dists);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        int from, to;
        cin >> from >> to;
        cout << worst[from - 1][to - 1] << endl;
    }
}

vector<vector<int>> floyd(vector<int>& times, vector<vector<int>>& dists) {
    int v = dists.size();
    vector<pair<int, int>> time_pairs;
    for (int i = 0; i < v; i++) time_pairs.emplace_back(times[i], i);
    sort(time_pairs.begin(), time_pairs.end());

    vector<vector<int>> worst(dists);

    for (int k = 0; k < v; k++) {
        int m = time_pairs[k].second;
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                dists[i][j] = min(dists[i][j], dists[i][m] + dists[m][j]);
                worst[i][j] = min(worst[i][j], dists[i][m] + dists[m][j] + times[m]);
            }
        }
    }

    return worst;
}