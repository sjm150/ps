#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int r, c, w; cin >> r >> c >> w;
        cout << "Case #" << tt << ": " << c / w * r + w - (c % w == 0) << '\n';
    }
}