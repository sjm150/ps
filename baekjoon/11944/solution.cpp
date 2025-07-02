#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    string ans;
    for (int i = 0; i < n && int(ans.size()) < m; i++) ans += to_string(n);
    if (int(ans.size()) > m) ans.resize(m);
    cout << ans << '\n';
}