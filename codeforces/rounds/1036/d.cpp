#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        if (k <= 2) {
            cout << "YES\n";
            continue;
        }

        vector<pair<int, int>> ord(n);
        for (int i = 0; i < n; i++) ord[i] = {a[i], i};
        sort(ord.begin(), ord.end());
        int ub = ord[k - 2].first;
        vector<int> b;
        for (int a: a) {
            if (a <= ub) b.push_back(a);
        }
        int sz = b.size();

        int l = 0, r = sz - 1, len = 0;
        while (l < r) {
            if (b[l] == b[r]) {
                len += 2;
                l++;
                r--;
            } else if (b[l] == ub) {
                l++;
            } else if (b[r] == ub) {
                r--;
            } else {
                break;
            }
        }
        if (l == r) len++;

        cout << (len >= k - 1 ? "YES\n" : "NO\n");
    }
}