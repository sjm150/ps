#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    vector<int> t(n);
    for (int &t: t) cin >> t;
    vector<pair<int, int>> ovr;
    int l = 0, r = 0;
    int seq = 0;
    while (r < n) {
        if (abs(seq) >= m) {
            ovr.emplace_back(l, r);
            l++;
            if (t[l - 1] < t[l]) seq--;
            else if (t[l - 1] > t[l]) seq++;
        } else {
            r++;
            if (r == n) break;
            if (t[r - 1] < t[r]) {
                if (seq < 0) {
                    l = r - 1;
                    seq = 1;
                } else {
                    seq++;
                }
            } else if (t[r - 1] > t[r]) {
                if (seq > 0) {
                    l = r - 1;
                    seq = -1;
                } else {
                    seq--;
                }
            }
        }
    }
    while (q--) {
        int a, b; cin >> a >> b;
        a--, b--;
        auto it = lower_bound(ovr.begin(), ovr.end(), make_pair(a, 0));
        cout << (it == ovr.end() || it->second > b ? "ja\n" : "nej\n");
    }
}