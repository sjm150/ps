#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int f = 1;
        for (int i = 1; i <= n && f - 3 < k; i++) f *= i;
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        vector<vector<int>> ans;

        if (n == 1 && k == 1) {
            cout << "YES\n";
            cout << 1 << '\n';
            continue;
        }

        if (k % 2) {
            if (k == 1 || f - 3 < k || n % 2 == 0) {
                cout << "NO\n";
                continue;
            }

            ans.push_back(p);
            for (int i = 0; i < n; i++) p[i] = (i + n / 2) % n + 1;
            ans.push_back(p);
            for (int i = 0; i < n; i++) p[i] = (n + 1) / 2 * 3 - ans[0][i] - ans[1][i];
            ans.push_back(p);
            iota(p.begin(), p.end(), 1);
            do {
                if (ans.size() == k) break;
                auto rp = p;
                for (int &p: rp) p = n + 1 - p;
                if (p == ans[0] || p == ans[1] || p == ans[2] || rp == ans[0] || rp == ans[1] || rp == ans[2]) continue;
                ans.push_back(p);
                ans.push_back(rp);
            } while (next_permutation(p.begin(), p.end()));
        } else {
            if (f < k) {
                cout << "NO\n";
                continue;
            }

            do {
                if (ans.size() == k) break;
                ans.push_back(p);
                auto rp = p;
                for (int &p: rp) p = n + 1 - p;
                ans.push_back(rp);
            } while (next_permutation(p.begin(), p.end()));
        }

        cout << "YES\n";
        for (auto &ans: ans) {
            for (int a: ans) cout << a << ' ';
            cout << '\n';
        }
    }
}