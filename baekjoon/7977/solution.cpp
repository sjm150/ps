#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, int> cnt;
    cnt['A'] = cnt['C'] = cnt['G'] = cnt['T'] = 0;
    for (char c: s) cnt[c]++;

    char mnc = 'A';
    for (auto [c, v]: cnt) {
        if (v < cnt[mnc]) mnc = c;
    }

    cout << cnt[mnc] << '\n';
    for (int i = 0; i < n; i++) cout << mnc;
    cout << '\n';
}