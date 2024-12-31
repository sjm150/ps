#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    while (n--) {
        int r, e, c; cin >> r >> e >> c;
        if (r + c < e) cout << "advertise\n";
        else if (r + c > e) cout << "do not advertise\n";
        else cout << "does not matter\n";
    }
}