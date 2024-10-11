#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> o, e;
    while (n--) {
        int a; cin >> a;
        if (a % 2) o.push_back(a);
        else e.push_back(a);
    }
    n = o.size();
    int m = e.size();

    function<int(int, int)> gcd = [&](int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    };

    vector<vector<int>> edges(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (gcd(o[i], e[j]) > 1) continue;
            ll sum = ll(o[i]) * o[i] + ll(e[j]) * e[j];
            ll sr = sqrt(sum);
            if (sum == sr * sr || sum == (sr - 1) * (sr - 1) || sum == (sr + 1) * (sr + 1)) edges[i].push_back(j);
        }
    }

    vector<int> mch(n, -1), rmch(m, -1);
    vector<bool> vst(n);
    function<bool(int)> bpm = [&](int cur) {
        vst[cur] = true;
        for (int nxt: edges[cur]) {
            if (rmch[nxt] < 0 || (!vst[rmch[nxt]] && bpm(rmch[nxt]))) {
                mch[cur] = nxt;
                rmch[nxt] = cur;
                return true;
            }
        }
        return false;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        fill(vst.begin(), vst.end(), false);
        if (bpm(i)) ans++;
    }
    cout << ans << '\n';
}