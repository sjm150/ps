#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int c[1000][1000];
bool conn[1000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    conn[0] = true;
    for (int i = 1; i < n; i++) pq.emplace(c[0][i], i);
    ll sum = 0;
    while (!pq.empty()) {
        auto [w, v] = pq.top(); pq.pop();
        if (conn[v]) continue;
        conn[v] = true;
        sum += w;
        for (int i = 0; i < n; i++) {
            if (!conn[i]) pq.emplace(c[v][i], i);
        }
    }
    cout << sum << '\n';
}