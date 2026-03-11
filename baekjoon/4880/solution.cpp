#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (;;) {
        int a, b, c;
        cin >> a >> b >> c;
        if (!a && !b && !c) break;
        if (b - a == c - b) cout << "AP " << 2 * c - b << '\n';
        else cout << "GP " << c * c / b << '\n';
    }
}