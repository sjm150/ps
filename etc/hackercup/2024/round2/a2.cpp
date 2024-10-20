#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    vector<ll> ms;
    ms.push_back(1);
    for (int l = 1; l < 18; l += 2) {
        for (int p = 2; p < 10; p++) {
            vector<string> hs;
            string s;
            function<void(int, int)> gen = [&](int idx, int mx) {
                if (idx == l / 2) {
                    hs.push_back(s);
                    return;
                }
                for (int i = 1; i <= mx; i++) {
                    s.push_back('0' + i);
                    gen(idx + 1, i);
                    s.pop_back();
                };
            };
            gen(0, p - 1);
            for (string &f: hs) {
                for (string &b: hs) {
                    ll cur = 0;
                    for (int i = f.size() - 1; i >= 0; i--) cur = cur * 10 + f[i] - '0';
                    cur = cur * 10 + p;
                    for (char c: b) cur = cur * 10 + c - '0';
                    ms.push_back(cur);
                }
            }
        }
    }
    sort(ms.begin(), ms.end());
    int T; cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        ll a, b; cin >> a >> b;
        int m; cin >> m;
        int cnt = 0;
        for (int i = lower_bound(ms.begin(), ms.end(), a) - ms.begin(); i < ms.size() && ms[i] <= b; i++) {
            if (ms[i] % m == 0) cnt++;
        }
        cout << "Case #" << testcase << ": "  << cnt << '\n';
    }
}