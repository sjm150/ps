#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    n = 1000 - n;
    int ans = 0;
    for (int c: {500, 100, 50, 10, 5, 1}) {
        ans += n / c;
        n %= c;
    }
    cout << ans << '\n';
}