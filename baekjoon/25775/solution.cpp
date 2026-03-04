#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> cnt(30, vector<int>(26, 0));
    while (n--) {
        string s;
        cin >> s;
        for (int i = 0; i < int(s.size()); i++) cnt[i][s[i] - 'a']++;
    }
    for (int i = 0; i < 30; i++) {
        int mx = *max_element(cnt[i].begin(), cnt[i].end());
        if (!mx) break;
        cout << i + 1 << ": ";
        for (int j = 0; j < 26; j++) {
            if (cnt[i][j] == mx) cout << char(j + 'a') << ' ';
        }
        cout << '\n';
    }
}