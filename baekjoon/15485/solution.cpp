#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    int cnt[3] = {s[0] == 'a', 0, 0};
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'a') cnt[0] = (cnt[0] * 2 + 1) % mod;
        else cnt[s[i] - 'a'] = (cnt[s[i] - 'a'] * 2 % mod + cnt[s[i] - 'a' - 1]) % mod;
    }
    cout << cnt[2] << '\n';
}