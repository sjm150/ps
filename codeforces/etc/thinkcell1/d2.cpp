#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<vector<int>> cnt(n, vector<int>(4));
        fill(cnt[0].begin(), cnt[0].end(), 0);
        if (s[0] == '1') cnt[0][3]++;
        else cnt[0][0]++;

        long long sum, ans;
        sum = ans = cnt[0][3];
        for (int i = 1; i < n; i++) {
            cnt[i][3] = 0;
            for (int j = 0; j < 3; j++) cnt[i][j] = cnt[i - 1][j + 1];
            cnt[i][0] += cnt[i - 1][0] + 1;
            if (s[i] == '1') {
                sum += cnt[i][0];
                swap(cnt[i][0], cnt[i][3]);
            }
            ans += sum;
        }

        cout << ans << '\n';
    }
}