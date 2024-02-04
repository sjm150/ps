#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int pre; cin >> pre;
    vector<pi> trv;
    while (--m) {
        int p; cin >> p;
        trv.emplace_back(min(p, pre), max(p, pre));
        pre = p;
    }
    sort(trv.begin(), trv.end());

    int tidx = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        while (!pq.empty() && pq.top() == i) pq.pop();
        while (tidx < trv.size() && trv[tidx].first == i) pq.push(trv[tidx++].second);
        int a, b, c; cin >> a >> b >> c;
        sum += min(ll(pq.size()) * a, ll(pq.size()) * b + c);
    }
    cout << sum << '\n';
}