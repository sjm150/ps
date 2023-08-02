#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> edges[32001];
int indeg[32001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        indeg[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) pq.push(i);
    }
    while (!pq.empty()) {
        int a = pq.top(); pq.pop();
        cout << a << ' ';
        for (int b: edges[a]) {
            indeg[b]--;
            if (indeg[b] == 0) pq.push(b);
        }
    }
    cout << '\n';
}