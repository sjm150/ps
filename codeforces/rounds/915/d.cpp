#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n);
        int z = 0;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            if (p[i] == 0) z = i;
        }

        stack<pair<int, int>> stk;
        stk.emplace(0, 0);
        ll maxs = 0, sum = 0;
        for (int i = z + 1; ; i++) {
            if (i == n) i = 0;
            if (i == z) break;
            int cnt = 1;
            while (stk.top().first > p[i]) {
                cnt += stk.top().second;
                sum -= ll(stk.top().first) * stk.top().second;
                stk.pop();
            }
            sum += ll(p[i]) * cnt;
            stk.emplace(p[i], cnt);
            if (maxs < sum) maxs = sum;
        }

        cout << maxs + n << '\n';
    }
}