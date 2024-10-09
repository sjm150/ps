#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 1e7;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<bool> isp(mx, true);
    vector<int> p;
    for (int i = 2; i < mx; i++) {
        if (!isp[i]) continue;
        p.push_back(i);
        for (ll j = ll(i) * i; j < mx; j += i) isp[j] = false;
    }
    int sz = p.size();
    int T; cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int n; cin >> n;
        int cnt = 0;
        for (int i = 2; i < sz && p[i] <= n; i++) {
            if (p[i] - p[i - 1] == 2) {
                if (cnt == 0) cnt++;
                cnt++;
            }
        }
        cout << "Case #" << testcase << ": "  << cnt << '\n';
    }
}