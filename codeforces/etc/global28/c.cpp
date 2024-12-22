#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        int l = 0;
        while (l < n && s[l] == '1') l++;
        l = n - l;
        if (l == 0) {
            s[n - 1] = '0';
            cout << 1 << ' ' << 1 << ' ' << 1 << ' ' << n << '\n';
            continue;
        }
        string mx(n, '0');
        int ml = 0, mr = 0;
        for (int i = 0; i + l <= n; i++) {
            string cur = s;
            for (int j = 0; j < l; j++) cur[n - l + j] = '1' - (cur[n - l + j] == s[i + j]);
            if (mx < cur) {
                mx = cur;
                ml = i + 1, mr = i + l;
            }
        }
        cout << 1 << ' ' << n << ' ' << ml << ' ' << mr << '\n';
    }
}