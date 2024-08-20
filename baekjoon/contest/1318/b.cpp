#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    map<char, char> l = {{'R', 'S'}, {'S', 'P'}, {'P', 'R'}};
    vector<map<string, int>> cnt(51);
    while (n--) {
        string s; cin >> s;
        for (int i = 1; i <= s.size(); i++) cnt[i][s.substr(0, i)]++;
    }
    for (int i = 1; i <= 50; i++) {
        for (auto &[s, c]: cnt[i]) {
            if (c <= k) {
                cout << i << '\n';
                for (char c: s) cout << l[c];
                cout << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
}