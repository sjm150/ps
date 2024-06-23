#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    auto dgt = [&](char c) {
        return '0' <= c && c <= '9';
    };

    long long ans = 0;
    int cnt[3] = {};
    for (char c: s) {
        if (dgt(c)) {
            int ncnt[3];
            for (int i = 0; i < 3; i++) ncnt[(c - '0' + i) % 3] = cnt[i];
            ncnt[(c - '0') % 3]++;
            ans += ncnt[0];
            swap(cnt, ncnt);
        } else  {
            fill(cnt, cnt + 3, 0);
        }
    }

    cout << ans << '\n';
}