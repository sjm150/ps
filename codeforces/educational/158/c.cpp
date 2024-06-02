#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& a, int maxa) {
    for (int ai: a) {
        if (ai != maxa) return false;
    }
    return true;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        int maxa = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            maxa = max(maxa, a[i]);
        }

        vector<int> ans;
        while (!check(a, maxa)) {
            if (maxa % 2) {
                maxa /= 2;
                for (int &ai: a) ai /= 2;
                ans.push_back(0);
            } else {
                maxa = (maxa + 1) / 2;
                for (int &ai: a) ai = (ai + 1) / 2;
                ans.push_back(1);
            }
        }

        cout << ans.size() << '\n';
        if (ans.size() && ans.size() <= n) {
            for (int a: ans) cout << a << ' ';
            cout << '\n';
        }
    }
}