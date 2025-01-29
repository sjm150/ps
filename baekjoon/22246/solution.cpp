#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<string, int>> tm;
    for (int i = 0; i < n * 2; i++) {
        string s; cin >> s;
        tm.emplace_back(s, i % 2);
    }
    sort(tm.begin(), tm.end());
    int ans = 0, cnt = 0;
    for (auto &[t, a]: tm) {
        if (a) cnt--;
        else cnt++;
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}