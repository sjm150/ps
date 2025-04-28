#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<vector<int>> nxt(n + 1, vector<int>(k));
    fill(nxt.back().begin(), nxt.back().end(), n);
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][s[i] - 'a'] = i;
    }

    vector<int> dst(n + 1, n);
    dst[n] = 0;
    for (int i = n - 1; i >= 0; i--) dst[i] = dst[*max_element(nxt[i + 1].begin(), nxt[i + 1].end())] + 1;

    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int idx = -1;
        for (char c: t) {
            if (idx == n) break;
            idx = nxt[idx + 1][c - 'a'];
        }
        cout << dst[idx] << '\n';
    }
}