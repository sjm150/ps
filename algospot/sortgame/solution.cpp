#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<int> vec;

map<vector<int>, int> dist;
void prepare_dist();
int dist_to_sort(vector<int>& vec);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        cin >> n;
        vec = vector<int>(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        prepare_dist();
        cout << dist_to_sort(vec) << endl;
    }
}

void prepare_dist() {
    vector<int> sorted(n);
    for (int i = 0; i < n; i++) sorted[i] = i;
    queue<vector<int>> q;

    dist[sorted] = 0;
    q.push(sorted);
    while (!q.empty()) {
        auto curr = q.front();
        int curr_dist = dist[curr];
        q.pop();

        for (int i = 0; i < n; i++) {
            for (int j = i + 2; j <= n; j++) {
                reverse(curr.begin() + i, curr.begin() + j);
                if (dist.find(curr) == dist.end()) {
                    dist[curr] = curr_dist + 1;
                    q.push(curr);
                }
                reverse(curr.begin() + i, curr.begin() + j);
            }
        }
    }
}

int dist_to_sort(vector<int>& vec) {
    vector<int> condensed(n);

    for (int i = 0; i < n; i++) {
        int less_count = 0;
        for (int j = 0; j < n; j++) {
            if (vec[i] > vec[j]) less_count++;
        }

        condensed[i] = less_count;
    }

    return dist[condensed];
}