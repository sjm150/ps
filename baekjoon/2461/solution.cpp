#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
typedef long long lint;
using namespace std;

int a[1000][1000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    int maxa = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
        sort(a[i], a[i] + m);
        pq.emplace(a[i][0], i, 0);
        maxa = max(maxa, a[i][0]);
    }
    int mind = 1e9;
    while (true) {
        int x, i, j;
        tie(x, i, j) = pq.top();
        pq.pop();
        mind = min(mind, maxa - x);
        if (j == m - 1) break;
        maxa = max(maxa, a[i][j + 1]);
        pq.emplace(a[i][j + 1], i, j + 1);
    }
    cout << mind << '\n';
}