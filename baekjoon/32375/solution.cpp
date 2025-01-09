#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a < k) s.push_back(a);
        else ans++;
    }
    sort(s.begin(), s.end());
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] + s[r] < k) {
            l++;
        } else {
            l++, r--;
            ans++;
        }
    }
    if (ans) cout << ans << '\n';
    else cout << -1 << '\n';
}