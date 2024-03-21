#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int c, h; cin >> c >> h;
    vector<bool> b(c + 1, false);
    b[0] = true;
    while (h--) {
        int v; cin >> v;
        for (int i = c; i >= v; i--) {
            if (b[i - v]) b[i] = true;
        }
    }
    for (int i = c; i >= 0; i--) {
        if (b[i]) {
            cout << i << '\n';
            break;
        }
    }
}