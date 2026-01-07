#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int l, n;
    cin >> l >> n;
    vector<string> s(n);
    for (auto &s: s) cin >> s;
    int k;
    cin >> k;

    map<string, int> cnt;
    for (auto &s: s) {
        for (int i = 0; i + k <= l; i++) cnt[s.substr(i, k)]++;
    }

    int ans = 0;
    for (auto &[s, cnt]: cnt) ans = max(ans, cnt);
    cout << ans << '\n';
}