#include <bits/stdc++.h>
using namespace std;

const int n = 41;

vector<int> ans;

int select(int n, int p, int l) {
    if (p == 1) {
        if (n == 0 && ans.size() > l){
            ans = vector<int>();
            return true;
        } else {
            return false;
        }
    }
    for (int i = n; i >= 3; i--) {
        if (p % i) continue;
        if (select(n - i, p / i, l + 1)) {
            ans.push_back(i);
            return true;
        }
    }
    if (p % 4 != 0 && p % 2 == 0) {
        if (select(n - 2, p / 2, l + 1)) {
            ans.push_back(2);
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int T; cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int p; cin >> p;
        ans = vector<int>(n + 2);
        for (int i = 0; i <= n; i++) {
            if (select(i, p, n - i)) {
                for (int j = 0; j < n - i; j++) ans.push_back(1);
            }
        }
        sort(ans.begin(), ans.end());
        if (ans.size() > n) {
            cout << "Case #" << testcase << ": " << -1 << '\n';
        } else {
            cout << "Case #" << testcase << ": " << ans.size();
            for (int a: ans) cout << ' ' << a;
            cout << '\n';
        }
    }
}