#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    int d = abs(a - b);
    if (d % 2) {
        cout << -1 << '\n';
    } else {
        int mn = 0;
        for (int i = d / 2; i; i /= 2) mn++;
        cout << mn << ' ' << (1 << mn) - d / 2 << '\n';
    }
}