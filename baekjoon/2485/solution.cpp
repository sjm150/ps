#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, fst; cin >> n >> fst;
    int g = 0;
    for (int i = 0; i < n - 2; i++) {
        int p; cin >> p;
        g = gcd(p - fst, g);
    }
    int lst; cin >> lst;
    lst -= fst;
    g = gcd(lst, g);
    cout << lst / g + 1 - n << '\n';
}