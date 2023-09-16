#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<vector<bool>> ispal;
int cnt[2501];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> s;
    n = s.length();
    ispal = vector<vector<bool>>(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) ispal[i][i] = true;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) ispal[i - 1][i] = true;
    }
    for (int l = 2; l < n; l++) {
        for (int i = l; i < n; i++) {
            if (ispal[i - l + 1][i - 1] && s[i - l] == s[i]) ispal[i - l][i] = true;
        }
    }
    fill(cnt, cnt + n + 1, 2500);
    cnt[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j--) {
            if (ispal[j - 1][i - 1]) cnt[i] = min(cnt[i], cnt[j - 1] + 1);
        }
    }
    cout << cnt[n] << '\n';
}