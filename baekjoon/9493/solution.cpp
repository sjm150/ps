#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (;;) {
        int m, a, b;
        cin >> m >> a >> b;
        if (m == 0) break;
        int x = round(double(m * 3600) / a / b * (b - a));
        cout << x / 3600 << ':' << setw(2) << setfill('0') << x / 60 % 60 << ':' << setw(2) << setfill('0') << x % 60 << '\n';
    }
}