#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> c(n), p(n), s(n);
    iota(c.begin(), c.end(), 0);
    for (int &p: p) cin >> p;
    for (int &s: s) cin >> s;

    vector<bool> vst(n, false);
    function<int(int)> dfs = [&](int cur) {
        vst[cur] = true;
        if (vst[s[cur]]) return 1;
        return dfs(s[cur]) + 1;
    };
    function<int(int, int)> gcd = [&](int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    };
    int l = 1;
    for (int i = 0; i < n; i++) {
        if (!vst[i]) {
            int cnt = dfs(i);
            l *= cnt / gcd(l, cnt);
        }
    }

    for (int i = 0; i < l; i++) {
        bool poss = true;
        for (int j = 0; j < n; j++) {
            if (j % 3 != p[c[j]]) {
                poss = false;
                break;
            }
        }
        if (poss) {
            cout << i << '\n';
            return 0;
        }
        vector<int> nc(n);
        for (int j = 0; j < n; j++) nc[s[j]] = c[j];
        swap(c, nc);
    }
    cout << -1 << '\n';
}