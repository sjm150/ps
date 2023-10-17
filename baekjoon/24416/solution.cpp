#include <bits/stdc++.h>
using namespace std;

int cnts[41];

int cnt(int n) {
    if (n <= 2) return 1;
    int& cache = cnts[n];
    if (cache) return cache;
    return cache = cnt(n - 1) + cnt(n - 2);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    cout << cnt(n) << ' ' << n - 2 << '\n';
}