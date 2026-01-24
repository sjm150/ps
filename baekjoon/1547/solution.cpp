#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    bool b[4] = {};
    b[1] = true;
    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        swap(b[x], b[y]);
    }
    cout << find(b, b + 4, true) - b << '\n';
}