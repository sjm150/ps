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
        set<pair<int, int>> occ;
        for (int i = 1; i < n; i++) occ.emplace(min(b[i - 1], b[i]), max(b[i - 1], b[i]));
        bool poss = false;
        for (int i = 1; i < n; i++) {
            if (occ.find(make_pair(min(a[i - 1], a[i]), max(a[i - 1], a[i]))) == occ.end()) {
                poss = true;
                break;
            }
        }
        cout << (poss ? "Alice\n" : "Bob\n");
    }
}