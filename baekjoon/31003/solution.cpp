#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    function<int(int, int)> gcd = [&](int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    };

    for (int i = 1; i < n; i++) {
        int t = i;
        for (int j = i - 1; j >= 0; j--) {
            if (gcd(a[j], a[i]) == 1) {
                if (a[j] > a[i]) t = j;
            } else {
                break;
            }
        }
        int v = a[i];
        for (int j = i; j > t; j--) a[j] = a[j - 1];
        a[t] = v;
    }

    for (int a: a) cout << a << ' ';
    cout << '\n';
}