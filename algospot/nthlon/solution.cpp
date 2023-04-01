#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int min_draw_time(vector<int>& a, vector<int>& b);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        int m;
        cin >> m;
        vector<int> a(m), b(m);
        for (int i = 0; i < m; i++) cin >> a[i] >> b[i];

        int result = min_draw_time(a, b);
        if (result > 0) cout << result << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
}

bool is_possible(vector<int>& diff) {
    bool plus = false, minus = false, zero = false;
    for (int val: diff) {
        if (val > 0) plus = true;
        else if (val < 0) minus = true;
        else return true;
    }

    return plus & minus;
}

int min_draw_time(vector<int>& a, vector<int>& b) {
    int m = a.size();
    vector<int> diff(m);
    for (int i = 0; i < m; i++) diff[i] = a[i] - b[i];
    if (!is_possible(diff)) return 0;

    vector<vector<int>> min_time(2, vector<int>(200, INT32_MAX));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < m; i++) {
        int& ref = min_time[diff[i] > 0][abs(diff[i])];
        if (ref > a[i]) {
            ref = a[i];
            pq.emplace(a[i], diff[i]);
        }
    }

    while (!pq.empty()) {
        int curr_time = pq.top().first;
        int curr_diff = pq.top().second;
        pq.pop();

        if (curr_diff == 0) return curr_time;
        if (curr_time > min_time[curr_diff > 0][abs(curr_diff)]) continue;

        for (int i = 0; i < m; i++) {
            if (curr_diff * diff[i] < 0) {
                int next_time = curr_time + a[i];
                int next_diff = curr_diff + diff[i];
                int& min_time_next = min_time[next_diff > 0][abs(next_diff)];

                if (next_time < min_time_next) {
                    min_time_next = next_time;
                    pq.emplace(next_time, next_diff);
                }
            }
        }
    }

    return 0;
}