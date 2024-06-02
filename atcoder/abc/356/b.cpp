#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> a(m);
    vector<vector<int>> x(n, vector<int>(m));
    for (int &a: a) cin >> a;
    for (auto &x: x) {
        for (int &x: x) cin >> x;
    }

    bool ok = true;
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) sum += x[j][i];
        if (sum < a[i]) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Yes\n" : "No\n");
}