#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mx = 2000;
    vector<bool> isp(mx, true);
    for (int i = 2; i < mx; i++) {
        if (!isp[i]) continue;
        for (int j = i * i; j < mx; j += i) isp[j] = false;
    }

    int n; cin >> n;
    int r = -1;
    vector<int> e, o;
    while (n--) {
        int a; cin >> a;
        if (r < 0) r = a % 2;
        if (a % 2 == r) e.push_back(a);
        else o.push_back(a);
    }
    n = e.size();
    int m = o.size();

    vector<vector<int>> edges(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isp[e[i] + o[j]]) edges[i].push_back(j);
        }
    }

    vector<int> mch(n), rmch(m);
    vector<bool> vst(n), chk(m, false);
    function<bool(int)> bpm = [&](int cur) {
        vst[cur] = true;
        for (int nxt: edges[cur]) {
            if (cur == 0 && chk[nxt]) continue;
            if (rmch[nxt] < 0 || (!vst[rmch[nxt]] && bpm(rmch[nxt]))) {
                mch[cur] = nxt;
                rmch[nxt] = cur;
                return true;
            }
        }
        return false;
    };

    vector<int> ans;
    for (;;) {
        int cnt = 0;
        fill(mch.begin(), mch.end(), -1);
        fill(rmch.begin(), rmch.end(), -1);
        for (int i = 0; i < n; i++) {
            fill(vst.begin(), vst.end(), false);
            if (bpm(i)) cnt++;
        }
        if (cnt * 2 == n + m) {
            ans.push_back(o[mch[0]]);
            chk[mch[0]] = true;
        } else {
            break;
        }
    }

    if (ans.size()) {
        sort(ans.begin(), ans.end());
        for (int a: ans) cout << a << ' ';
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}