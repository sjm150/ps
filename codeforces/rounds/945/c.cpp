#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n);
        bool odd = false;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            if (p[i] == 1) odd = i & 1;
        }

        vector<int> ans(n);
        vector<pair<int, int>> tmp(n / 2);
        for (int b = 0; b < 2; b++) {
            for (int i = 0; i < n; i += 2) tmp[i / 2] = make_pair(p[i + b], i + b);
            sort(tmp.begin(), tmp.end());
            if (b == odd) {
                int cur = n / 2;
                for (auto [v, i]: tmp) ans[i] = cur--;
            } else {
                int cur = n;
                for (auto [v, i]: tmp) ans[i] = cur--;
            }
        }

        for (int a: ans) cout << a << ' ';
        cout << '\n';
    }
}