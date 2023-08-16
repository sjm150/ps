#include <bits/stdc++.h>
using namespace std;

int s[100000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, d; cin >> n >> m >> d;
        for (int i = 0; i < m; i++) cin >> s[i];
        int cnt0 = 0, cnt1 = 0;
        int tot = 1;
        if (s[0] == 1) {
            cnt0++;
        } else {
            tot += (s[0] - 2) / d + 1;
            int ori = (s[0] - 2) / d + (s[1] - s[0] - 1) / d + 1;
            int del = (s[1] - 2) / d;
            if (ori > del) cnt1++;
            else cnt0++;
        }
        for (int i = 1; i < m - 1; i++) {
            tot += (s[i] - s[i - 1] - 1) / d + 1;
            int ori = (s[i] - s[i - 1] - 1) / d + (s[i + 1] - s[i] - 1) / d + 1;
            int del = (s[i + 1] - s[i - 1] - 1) / d;
            if (ori > del) cnt1++;
            else cnt0++;
        }
        int ori = (s[m - 1] - s[m - 2] - 1) / d + (n - s[m - 1]) / d + 1;
        tot += ori;
        int del = (n - s[m - 2]) / d;
        if (ori > del) cnt1++;
        else cnt0++;
        if (cnt1 > 0) cout << tot - 1 << ' ' << cnt1 << '\n';
        else cout << tot << ' ' << cnt0 << '\n';
    }
}