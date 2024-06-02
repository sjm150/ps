#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();

        vector<int> sum(n);
        sum[0] = (s[0] == '(' ? 1 : -1);
        for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);

        map<int, int> l;
        long long ans = 0;
        for (int s: sum) {
            auto it = l.find(s);
            if (it != l.end()) ans += it->second++;
            else l.emplace(s, 1);
            it = l.begin();
            while (it != l.end() && it->first * 2 < s) it = l.erase(it);
        }

        cout << ans << '\n';
    }
}