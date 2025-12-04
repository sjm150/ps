#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mod = 720;
    int m;
    cin >> m;
    vector<int> t(m);
    for (int &t: t) {
        string s;
        cin >> s;
        t = (stoi(s.substr(0, 2)) - 1) * 60 + stoi(s.substr(3, 2));
    }

    int ans = m;
    for (int r = 0; r < mod; r++) {
        vector<int> u;
        for (int i = 0; i < m; i++) u.push_back((t[i] + r * i) % mod);
        sort(u.begin(), u.end());
        ans = min(ans, int(unique(u.begin(), u.end()) - u.begin()));
    }
    cout << ans << '\n';
}