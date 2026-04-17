#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k, b;
    cin >> n >> k >> b;
    vector<int> x(n);
    for (int &x: x) cin >> x;
    for (int i = 1; i < n; i++) x[i] += x[i - 1];
    auto get = [&](int i) { return i / n * x[n - 1] + x[i % n]; };
    cout << get((b - 2 + n) % n + k) - get((b - 2 + n) % n) << '\n';
}