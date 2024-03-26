#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string a; cin >> a;
        int tot[2] = {0, 0};
        for (char c: a) tot[c - '0']++;

        int sum[2] = {0, 0};
        vector<int> cnds;
        if (tot[1] >= tot[0]) cnds.push_back(0);
        for (int i = 0; i < n; i++) {
            sum[a[i] - '0']++;
            if (sum[0] - sum[1] >= 0 && tot[1] - sum[1] - tot[0] + sum[0] >= 0) cnds.push_back(i + 1);
        }

        int ans = cnds[0];
        for (int c: cnds) {
            if (abs(n - 2 * ans) > abs(n - 2 * c)) ans = c;
        }
        cout << ans << '\n';
    }
}