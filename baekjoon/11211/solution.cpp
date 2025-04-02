#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    double d; cin >> d;
    int n; cin >> n;
    int sum = -1;
    double l = 0, r = 1;
    for (int i = 1; i <= n; i++) {
        int c; cin >> c;
        sum += c;
        l = max(l, d * i - sum - 1);
        r = min(r, d * i - sum);
    }
    cout << (l < r ? "possible\n" : "impossible\n");
}