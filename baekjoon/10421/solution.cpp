#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> s;
vector<bool> poss(10, false);

vector<int> prd(10), plen(10);
vector<vector<int>> opt;
int ans;

void sel(int res, int idx) {
    if (idx == s[1]) {
        ans++;
        int rlen = 0;
        for (; res; res /= 10, rlen++) {
            if (!poss[res % 10]) {
                ans--;
                return;
            }
        }
        if (rlen != s.back()) ans--;
        return;
    }

    for (int o: opt[idx]) sel(res * 10 + prd[o], idx + 1);
}

void fst(int f, int len) {
    if (len == s[0]) {
        for (int i = 1; i < 10; i++) {
            if (poss[i]) {
                prd[i] = f * i;
                plen[i] = 0;
                for (int p = prd[i]; p; p /= 10, plen[i]++) {
                    if (!poss[p % 10]) prd[i] = -1;
                }
            } else {
                prd[i] = -1;
            }
        }

        opt = vector<vector<int>>(s[1]);
        for (int i = 0; i < s[1]; i++) {
            int l = s[2 + i];
            for (int j = 1; j < 10; j++) {
                if (prd[j] > 0 && plen[j] == l) opt[i].push_back(j);
            }
        }

        sel(0, 0);
        return;
    }

    for (int i = 1; i < 10; i++) {
        if (poss[i]) fst(10 * f + i, len + 1);
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        poss[x] = true;
    }

    fst(0, 0);
    cout << ans << '\n';
}