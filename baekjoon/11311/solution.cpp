#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b, d; cin >> a >> b >> d;
        if (a < b) swap(a, b);
        function<int(int, int)> gcd = [&](int a, int b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        };
        cout << (d % gcd(a, b) == 0 ? "Yes\n" : "No\n");
    }
}