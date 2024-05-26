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

        int i = 1;
        for (; i < n; i++) {
            if (a[i] % a[0]) break;
        }
        bool poss = true;
        for (int j = i + 1; j < n; j++) {
            if ((a[j] % a[0]) && (a[j] % a[i])) {
                poss = false;
                break;
            }
        }

        cout << (poss ? "YES\n" : "NO\n");
    }
}