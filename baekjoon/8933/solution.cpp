#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll mx = 600;
    unordered_map<char, ll> val = {{'A', 1}, {'G', mx}, {'T', mx * mx}, {'C', mx * mx * mx}};
    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        string s; cin >> s;
        int n = s.size();
        if (k > n) {
            cout << 0 << '\n';
            continue;
        }
        unordered_map<ll, int> cnt;
        ll cur = 0;
        for (int i = 0; i < k; i++) cur += val[s[i]];
        cnt[cur]++;
        for (int i = k; i < n; i++) {
            cur -= val[s[i - k]];
            cur += val[s[i]];
            cnt[cur]++;
        }
        int ans = 0;
        for (auto [k, cnt]: cnt) ans = max(ans, cnt);
        cout << ans << '\n';
    }
}