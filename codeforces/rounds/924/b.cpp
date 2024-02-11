#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        set<int> occ;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int ai; cin >> ai;
            if (occ.find(ai) == occ.end()) {
                a.push_back(ai);
                occ.insert(ai);
            }
        }
        sort(a.begin(), a.end());
        int sz = a.size();

        int s = 0, e = 0, mcnt = 1;
        while (e < sz) {
            if (a[s] + n <= a[e]) {
                s++;
            } else {
                mcnt = max(mcnt, e - s + 1);
                e++;
            }
        }

        cout << mcnt << '\n';
    }
}