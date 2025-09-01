#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        bool b[10] = {};
        for (; x; x /= 10) b[x % 10] = true;
        cout << accumulate(b, b + 10, 0) << '\n';
    }
}