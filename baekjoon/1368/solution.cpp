#include <iostream>
#include <queue>
using namespace std;

int w[300];
int p[300][300];
bool vst[300];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) pq.emplace(w[i], i);
    int sum = 0;
    while (!pq.empty()) {
        auto [c, v] = pq.top(); pq.pop();
        if (vst[v]) continue;
        vst[v] = true;
        sum += c;
        for (int i = 0; i < n; i++) {
            if (!vst[i]) pq.emplace(p[v][i], i);
        }
    }
    cout << sum << '\n';
}