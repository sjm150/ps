#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int ocnt = 0, ecnt = 0;
        while (n--) {
            int a; cin >> a;
            if (a % 2) ocnt++;
            else ecnt++;
        }
        if (ecnt) cout << ocnt + 1 << '\n';
        else cout << max(0, ocnt - 1) << '\n';
    }
}