#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int x = 0, mx = 0, xh = 0;
        for (int a: a) {
            if (xh < a) xh++;
            else if (xh > a) xh--;
            xh = max(xh, mx);
            if (x < a) x++;
            else if (x > a) x--;
            mx = max(mx, x);
        }
        if (n == xh) xh--;
        cout << xh << '\n';
    }
}