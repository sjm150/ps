#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mod = 998244353;
    int n, m; cin >> n >> m;
    vector<int> ex2(n + 1);
    ex2[0] = 1;
    for (int i = 1; i <= n; i++) ex2[i] = ex2[i - 1] * 2 % mod;
    vector<pair<int, int>> lr(n);
    for (auto &[l, r]: lr) cin >> l >> r;
    sort(lr.begin(), lr.end());
    vector<int> a(m);
    for (int &a: a) cin >> a;
    sort(a.begin(), a.end());

    int idx = 0, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int a: a) {
        while (!pq.empty() && pq.top() < a) pq.pop();
        int cnt = pq.size();
        for (; idx < n && lr[idx].first <= a; idx++) {
            if (lr[idx].second >= a) pq.push(lr[idx].second);
        }
        ans = ((ans + ex2[pq.size()]) % mod - ex2[cnt] + mod) % mod;
    }
    cout << ans << '\n';
}