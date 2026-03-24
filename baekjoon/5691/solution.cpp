#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (;;) {
        int a, b;
        cin >> a >> b;
        if (a == 0) break;
        cout << 2 * a - b << '\n';
    }
}