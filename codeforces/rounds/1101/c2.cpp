#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x, s;
        cin >> n >> x >> s;
        string u;
        cin >> u;

        auto calc = [&](int ic) {
            vector<int> ip;
            int rem = x;
            for (int i = 0; i < n && rem; i++) {
                if (u[i] == 'I') {
                    ip.push_back(i);
                    rem--;
                } else if (u[i] == 'A' && ic) {
                    ip.push_back(i);
                    rem--;
                    ic--;
                }
            }

            int ret = 0, cnt = 0;
            for (int i = n - 1; i >= 0 && !ip.empty(); i--) {
                if (i == int(ip.back())) {
                    int sub = min(s - 1, cnt);
                    cnt -= sub;
                    ret += sub + 1;
                    ip.pop_back();
                } else if (u[i] != 'I') {
                    cnt++;
                }
            }

            return ret;
        };

        int ac = count(u.begin(), u.end(), 'A');
        int l = 0, r = ac;
        while (l < r) {
            int m = (l + r) / 2;
            if (calc(m) < calc(m + 1)) l = m + 1;
            else r = m;
        }
        cout << calc(r) << '\n';
    }
}