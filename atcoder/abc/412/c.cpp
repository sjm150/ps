#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> s(n);
        for (int &s: s) cin >> s;
        sort(s.begin() + 1, s.end() - 1);

        int idx = 0, ans = 2;
        while (idx < n - 2 && s[idx] * 2 < s[n - 1]) {
            int nxt = prev(upper_bound(s.begin() + idx + 1, s.end() - 1, s[idx] * 2)) - s.begin();
            if (idx == nxt) break;
            idx = nxt;
            ans++;
        }

        cout << (s[idx] * 2 < s[n - 1] ? -1 : ans) << '\n';
    }
}