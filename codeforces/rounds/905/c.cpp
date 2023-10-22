#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100000];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<int, int> fst, lst;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (fst.find(a[i]) == fst.end()) fst[a[i]] = i;
            lst[a[i]] = i;
        }

        vector<int> lidx;
        for (auto [v, i]: lst) lidx.push_back(i);
        sort(lidx.begin(), lidx.end());
        ll cnt = 0;
        for (auto [v, i]: fst) {
            cnt += lidx.end() - lower_bound(lidx.begin(), lidx.end(), i);
        }


        cout << cnt << '\n';
    }
}