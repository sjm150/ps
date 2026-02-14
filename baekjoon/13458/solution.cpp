#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    int b, c;
    cin >> b >> c;
    long long ans = 0;
    for (int a: a) ans += 1 + max(0, a - b + c - 1) / c;
    cout << ans << '\n';
}