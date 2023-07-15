#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, l;
int init[51];
pair<int, int> sec[51];

int maxdiv(int i) {
    return (sec[i].first + sec[i].second - 1) / sec[i].second;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> l;
    for (int i = 0; i < n; i++) cin >> init[i];
    init[n] = l;
    sort(init, init + n);
    int prev = 0;
    for (int i = 0; i <= n; i++) {
        sec[i] = {init[i] - prev, 1};
        prev = init[i];
    }

    priority_queue<pair<pair<int, int>, int>> pq;
    for (int i = 0; i <= n; i++) pq.push({{sec[i].first, -sec[i].second}, i});
    while (m--) {
        int tar = pq.top().second;
        pq.pop();
        sec[tar].second++;
        pq.push({{maxdiv(tar), -sec[tar].second}, tar});
    }
    cout << maxdiv(pq.top().second) << '\n';
}