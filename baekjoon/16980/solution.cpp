#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int h, w; cin >> h >> w;
    vector<string> s(h);
    for (auto &s: s) cin >> s;
    vector<vector<int>> ocnt(h, vector<int>(w, 0)), icnt = ocnt;
    for (int i = 0; i < h; i++) {
        ocnt[i][w - 1] = s[i][w - 1] == 'O';
        for (int j = w - 2; j >= 0; j--) ocnt[i][j] = ocnt[i][j + 1] + (s[i][j] == 'O');
    }
    for (int j = 0; j < w; j++) {
        icnt[h - 1][j] = s[h - 1][j] == 'I';
        for (int i = h - 2; i >= 0; i--) icnt[i][j] = icnt[i + 1][j] + (s[i][j] == 'I');
    }
    long long ans = 0;
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w - 1; j++) {
            if (s[i][j] == 'J') ans += ocnt[i][j + 1] * icnt[i + 1][j];
        }
    }
    cout << ans << '\n';
}