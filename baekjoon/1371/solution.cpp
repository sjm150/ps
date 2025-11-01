#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    int cnt[26] = {};
    while (cin >> s) {
        for (char c: s) cnt[c - 'a']++;
    }
    int mx = *max_element(cnt, cnt + 26);
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == mx) cout << char(i + 'a');
    }
    cout << '\n';
}