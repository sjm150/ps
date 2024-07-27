#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for (int &a: a) {
        cin >> a;
        a %= t;
    }
    sort(a.begin(), a.end());

    queue<int> q;
    int idx = 0;
    while (idx < n && a[idx] - a[0] <= a[0] + t - a[idx]) idx++;
    for (int i = idx; i < n; i++) q.push(a[i] - t);
    for (int i = 0; i < idx; i++) q.push(a[i]);

    int ans = (q.back() - q.front() + 1) / 2;
    for (int i = 1; i < n; i++) {
        while (a[i] - q.front() >= q.front() + t - a[i]) {
            q.push(q.front() + t);
            q.pop();
        }
        ans = min(ans, (q.back() - q.front() + 1) / 2);
    }
    cout << ans << '\n';
}