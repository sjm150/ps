#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int x = sqrt(n);
    if ((x + 1) * (x + 1) <= n) x++;
    cout << x << '\n';
}