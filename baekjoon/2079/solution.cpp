#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size();

    vector<vector<bool>> pal(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) pal[i][i] = true;
    for (int i = 1; i < n; i++) pal[i - 1][i] = s[i - 1] == s[i];
    for (int l = 2; l < n; l++) {
        for (int i = l; i < n; i++) {
            if (pal[i - l + 1][i - 1] && s[i - l] == s[i]) pal[i - l][i] = true;
        }
    }

    vector<int> cnt(n, n);
    for (int i = 0; i < n; i++) {
        if (pal[0][i]) {
            cnt[i] = 1;
        } else {
            for (int j = 0; j < i; j++) {
                if (pal[j + 1][i]) cnt[i] = min(cnt[i], cnt[j] + 1);
            }
        }
    }

    cout << cnt[n - 1] << '\n';
}