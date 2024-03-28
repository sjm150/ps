#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    n *= 3;

    vector<vector<bool>> cnt(n, vector<bool>(n, false));
    cnt[0][n - 1] = true;
    int l = n - 1;
    for (; l >= 1; l--) {
        char c = "BLD"[(n - 1 - l) % 3];
        if (c == s[l] && cnt[0][l]) cnt[0][l - 1] = true;
        if (c == s[n - l - 1] && cnt[n - l - 1][n - 1]) cnt[n - l][n - 1] = true;
        bool poss = cnt[0][l - 1] || cnt[n - l][n - 1];
        for (int i = 1; i + l < n; i++) {
            if (c == s[i - 1] && cnt[i - 1][i + l - 1]) cnt[i][i + l - 1] = true;
            if (c == s[i + l] && cnt[i][i + l]) cnt[i][i + l - 1] = true;
            poss |= cnt[i][i + l - 1];
        }
        if (!poss) break;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'D' && cnt[i][i]) {
            l--;
            break;
        }
    }
    cout << n - 1 - l << '\n';
}