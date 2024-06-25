#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int, int>> xa(n);
    for (auto &[x, a]: xa) cin >> x >> a;
    sort(xa.begin(), xa.end());

    long long sum = 0, cur = 0;
    for (auto [x, a]: xa) sum += a;

    int i = 0;
    for (; i < n - 1; i++) {
        cur += xa[i].second;
        if (cur * 2 >= sum) break;
    }
    cout << xa[i].first << '\n';
}