#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> s(n);
    for (int &s: s) cin >> s;
    s.resize(n + m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + m; j++) {
            int t; cin >> t;
            s[i] -= t;
            s[j] += t;
        }
    }
    for (int s: s) cout << s << ' ';
    cout << '\n';
}