#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n - 2; i++) ans += i * (n - 2 - i);
    cout << ans * n / 4 << '\n';
}