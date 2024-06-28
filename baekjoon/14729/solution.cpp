#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<double> s(n);
    for (auto &s: s) cin >> s;
    vector<double> ans(7, 1000);
    for (auto s: s) {
        for (int i = 0; i < 7; i++) {
            if (ans[i] > s) swap(ans[i], s);
        }
    }
    cout << fixed << setprecision(3);
    for (double a: ans) cout << a << '\n';
}