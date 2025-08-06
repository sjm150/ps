#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mod = 999017;
    int n;
    cin >> n;
    int tot = 1;
    for (int i = 2; i <= n; i++) tot = tot * i % mod;
    int cnt = 1;
    {
        int a = 1, b = 1;
        for (int i = 0; i < n - 1; i++) {
            cnt = (3 * b - a) % mod;
            a = b;
            b = cnt;
        }
    }
    cout << (tot - cnt + mod) % mod << '\n';
}