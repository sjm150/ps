#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int lmax = 0, minx = inf;
    stack<pair<int, int>> stk;
    stk.emplace(0, n);
    for (int i = n - 1; i > 0; i--) {
        if (stk.top().first < a[i] + i) stk.emplace(a[i] + i, i);
    }
    for (int i = 0; i < n; i++) {
        if (stk.top().second == i) stk.pop();
        minx = min(minx, max(lmax, max(a[i], stk.top().first)));
        lmax = max(lmax, a[i] + n - 1 - i);
    }
    cout << minx << '\n';
}