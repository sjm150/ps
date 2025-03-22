#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    function<int(int, int)> gcd = [&](int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    };
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        sort(a.begin(), a.end());
        int g = 0;
        for (int i = 1; i < n; i++) g = gcd(g, a[i] - a[i - 1]);
        if (g) cout << g << '\n';
        else cout << "INFINITY\n";
    }
}