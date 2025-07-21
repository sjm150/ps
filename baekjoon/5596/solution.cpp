#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a[4], b[4];
    for (int &a: a) cin >> a;
    for (int &b: b) cin >> b;
    cout << max(accumulate(a, a + 4, 0), accumulate(b, b + 4, 0)) << '\n';
}