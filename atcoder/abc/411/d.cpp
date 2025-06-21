#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;

    vector<pair<int, string>> ss;
    int r = -1;
    vector<int> ps(n, -1);
    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int p;
            cin >> p;
            ps[p - 1] = r;
        } else if (c == 2) {
            int p;
            string s;
            cin >> p >> s;
            p--;
            ss.emplace_back(ps[p], s);
            ps[p] = ss.size() - 1;
        } else {
            int p;
            cin >> p;
            r = ps[p - 1];
        }
    }

    function<void(int)> prnt = [&](int i) {
        if (i >= 0) {
            auto [pre, s] = ss[i];
            prnt(pre);
            cout << s;
        }
    };
    prnt(r);
    cout << '\n';
}