#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int cnt = 0;
        for (; x; x /= 2) cnt++;
        cout << cnt * 2 + 1 << '\n';
    }
}