#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        sort(a.begin(), a.end());
        int pre = 0;
        bool poss = false;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] != a[i]) {
                if ((i - pre) % 2) poss = true;
                pre = i;
            }
        }
        if ((n - pre) % 2) poss = true;
        cout << (poss ? "YES\n" : "NO\n");
    }
}