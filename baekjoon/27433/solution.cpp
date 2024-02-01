#include <bits/stdc++.h>
using namespace std;

long long fact(int n) {
    if (n == 0) return 1;
    return fact(n - 1) * n;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    cout << fact(n) << '\n';
}