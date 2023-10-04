#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    while (n--) {
        int a; cin >> a;
        pq.push(a);
    }
    while (m--) {
        ll x = pq.top(); pq.pop();
        ll y = pq.top(); pq.pop();
        pq.push(x + y);
        pq.push(x + y);
    }
    ll sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum << '\n';
}