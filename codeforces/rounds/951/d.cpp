#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        bool poss = true, ovr = false;
        int i = 0, cnt = -1;
        while (i < n && poss) {
            int j = i;
            while (s[i] == s[j]) j++;
            if (j - i < k) {
                cnt = j - i;
                poss = false;
            } else if (j - i > k) {
                cnt = j - i - k;
                poss = false;
                ovr = true;
            }
            i = j;
        }

        if (i == n && poss) {
            cout << n << '\n';
            continue;
        }

        int ans = i;
        i = n - 1;
        while (s[i] == s[ans - 1]) i--;
        if (n - 1 - i + cnt != k) {
            cout << -1 << '\n';
            continue;
        }

        poss = true;
        while (ans <= i && poss) {
            int j = i;
            while (s[i] == s[j]) j--;
            if (i - j != k) {
                poss = false;
                break;
            }
            i = j;
        }

        if (poss) cout << ans - (ovr ? k : 0) << '\n';
        else cout << -1 << '\n';
    }
}