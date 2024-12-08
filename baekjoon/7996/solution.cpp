#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mx = 1e4;
    vector<bool> isp(mx + 1, true);
    vector<int> p;
    for (int i = 2; i <= mx; i++) {
        if (!isp[i]) continue;
        p.push_back(i);
        if (p.size() == 70) break;
        for (int j = i * i; j <= mx; j += i) isp[j] = false;
    }
    int sz = p.size();

    vector<vector<double>> lgs(sz, vector<double>(mx + 1, 0));
    vector<vector<int>> pre(sz, vector<int>(mx + 1, 0));
    for (int i = 0; i < sz; i++) {
        if (i) lgs[i] = lgs[i - 1];
        for (int j = mx; j; j--) {
            for (int k = p[i]; j - k >= 0; k *= p[i]) {
                double l = log(k);
                if (lgs[i][j] < lgs[i][j - k] + l) {
                    lgs[i][j] = lgs[i][j - k] + l;
                    pre[i][j] = k;
                }
            }
        }
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> ps;
        for (int i = sz - 1; i >= 0; i--) {
            if (pre[i][n]) {
                ps.push_back(pre[i][n]);
                n -= pre[i][n];
            }
        }
        sort(ps.begin(), ps.end());
        int cur = 1;
        for (int i = 0; i < n; i++) cout << cur++ << ' ';
        for (int p: ps) {
            int nxt = cur + p;
            for (int i = cur + 1; i < nxt; i++) cout << i << ' ';
            cout << cur << ' ';
            cur = nxt;
        }
        cout << '\n';
    }
}