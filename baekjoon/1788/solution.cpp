#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9;

int fib[1000000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i <= abs(n); i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] >= mod) fib[i] -= mod;
    }
    if (n == 0) cout << "0\n0\n";
    else if (n > 0) cout << "1\n" << fib[n] << '\n';
    else cout << (n % 2 == 0 ? "-": "") << "1\n" << fib[-n] << '\n';
}