#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi;

vector<pi> edges[1001];
bool con[1001];
int cnt(priority_queue<pi>& pq) {
    int ans = 0;
    while (!pq.empty()) {
        auto [c, v] = pq.top(); pq.pop();
        if (con[v]) continue;
        con[v] = true;
        if (c == 0) ans++;
        for (auto& e: edges[v]) {
            if (!con[e.second]) pq.emplace(e);
        }
    }
    return ans;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    m++;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].emplace_back(c, b);
        edges[b].emplace_back(c, a);
    }
    priority_queue<pi> pq;
    con[0] = true;
    for (auto& e: edges[0]) pq.emplace(e);
    int mincnt = cnt(pq);
    for (int i = 0; i <= n; i++) {
        con[i] = false;
        for (auto& e: edges[i]) e.first = -e.first;
    }
    con[0] = true;
    for (auto& e: edges[0]) pq.emplace(e);
    int maxcnt = cnt(pq);
    cout << maxcnt * maxcnt - mincnt * mincnt << '\n';
}