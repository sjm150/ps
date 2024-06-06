#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int &a: a) cin >> a;
        for (int &b: b) cin >> b;
        int m; cin >> m;
        vector<int> d(m);
        for (int &d: d) cin >> d;

        multiset<int> dif;
        bool lst = false;
        for (int i = 0; i < n; i++) {
            if (d.back() == b[i]) lst = true;
            if (a[i] != b[i]) dif.insert(b[i]);
        }

        if (!lst) {
            cout << "NO\n";
            continue;
        }

        for (int d: d) {
            auto it = dif.find(d);
            if (it != dif.end()) dif.erase(it);
        }

        cout << (dif.empty() ? "YES\n" : "NO\n");
    }
}