#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        double d, a, b, f;
        cin >> n >> d >> a >> b >> f;
        cout << n << ' ' << d / (a + b) * f << '\n';
    }
}