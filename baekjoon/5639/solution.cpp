#include <bits/stdc++.h>
using namespace std;
const int mx = 1e7;

int print(int cur, int lim) {
    int nxt = mx;
    if (!cin.eof()) {
        cin >> nxt;
        if (nxt < cur) nxt = print(nxt, cur);
        if (lim == 0 || nxt < lim) nxt = print(nxt, lim);
    }
    if (cur < mx) cout << cur << '\n';
    return nxt;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int r; cin >> r;
    print(r, 0);
}