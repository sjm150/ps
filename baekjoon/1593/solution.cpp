#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int g, l; cin >> g >> l;
    string w, s; cin >> w >> s;

    vector<int> cnt(52, 0);
    auto idx = [&](char c) {
        if ('a' <= c && c <= 'z') return c - 'a';
        else return c - 'A' + 26;
    };
    auto chk = [&]() {
        for (int c: cnt) {
            if (c) return false;
        }
        return true;
    };

    for (char c: w) cnt[idx(c)]--;
    for (int i = 0; i < g - 1; i++) cnt[idx(s[i])]++;

    int ans = 0;
    for (int i = g - 1; i < l; i++) {
        cnt[idx(s[i])]++;
        if (chk()) ans++;
        cnt[idx(s[i - g + 1])]--;
    }
    cout << ans << '\n';
}