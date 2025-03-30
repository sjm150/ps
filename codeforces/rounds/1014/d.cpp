#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') a[i] = 0;
            else if (s[i] == 'I') a[i] = 1;
            else a[i] = 2;
        }

        int cnt[3] = {};
        for (int a: a) cnt[a]++;
        int ord[3];
        for (int i = 0; i < 3; i++) ord[i] = cnt[i];
        sort(ord, ord + 3);
        
        int i = 0;
        for (; i < n - 1; i++) {
            if ((cnt[a[i]] == ord[2] || cnt[a[i + 1]] == ord[2]) && a[i] != a[i + 1]) break;
        }
        if (i == n - 1) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> ans;
        if (cnt[a[i]] == ord[2]) {
            for (int j = 0; j < ord[2] - ord[1]; j++) {
                ans.push_back(i);
                ans.push_back(i);
            }
        } else {
            for (int j = 0; j < ord[2] - ord[1]; j++) {
                ans.push_back(i + ans.size());
                ans.push_back(i + ans.size());
            }
            a[i + 1] = 3 - a[i] - a[i + 1];
        }
        if (cnt[a[i]] == ord[0]) {
            for (int j = 0; j < ord[1] - ord[0]; j++) {
                ans.push_back(i);
                ans.push_back(i + 1);
                ans.push_back(i);
                ans.push_back(i + 1);
            }
        } else if (cnt[a[i + 1]] == ord[0]) {
            for (int j = 0; j < ord[1] - ord[0]; j++) {
                ans.push_back(i);
                ans.push_back(i);
                ans.push_back(i + 1);
                ans.push_back(i + 2);
            }
        } else {
            for (int j = 0; j < ord[1] - ord[0]; j++) {
                ans.push_back(i);
                ans.push_back(i);
                ans.push_back(i + 1);
                ans.push_back(i + 1);
            }
        }

        cout << ans.size() << '\n';
        for (int a: ans) cout << a + 1 << '\n';
    }
}