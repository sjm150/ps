#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m; cin >> m;
    string s; cin >> s;
    int n = s.size();

    map<char, int> idx = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    vector<int> cnt(4);
    int ans = n;
    for (int p = 1; p <= m; p++) {
        int rpl = n;
        for (int i = 0; i < p; i++) {
            fill(cnt.begin(), cnt.end(), 0);
            for (int j = i; j < n; j += p) {
                cnt[idx[s[j]]]++;
            }
            int maxc = 0;
            for (int c: cnt) maxc = max(maxc, c);
            rpl -= maxc;
        }
        ans = min(ans, rpl);
    }

    cout << ans << '\n';
}