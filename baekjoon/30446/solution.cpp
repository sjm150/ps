#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    ll n = stoll(s);
    int len = s.size();

    vector<int> cnt = {1, 9, 9};
    cnt.resize(max(3, len));
    for (int i = 3; i < len; i++) cnt[i] = 10 * cnt[i - 2];

    int ans = 0;
    for (int i = 1; i < len; i++) ans += cnt[i];
    for (int i = 0; i < (len + 1) / 2; i++) {
        int d = s[i] - '0';
        if (i == 0) d--;
        int l = max(0, len - 2 * i - 2);
        if (l) ans += d * cnt[l] / 9 * 10;
        else ans += d;
    }
    int i = len / 2 - 1;
    for (; i >= 0; i--) {
        if (s[i] < s[len - 1 - i]) {
            ans++;
            break;
        } else if (s[i] > s[len - 1 - i]) {
            break;
        }
    }
    if (i < 0) ans++;

    cout << ans << '\n';
}