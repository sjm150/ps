#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, s, g, p, d;
    cin >> n >> s >> g >> p >> d;
    string t;
    cin >> t;
    int ans = 0, pre = 0;
    for (char c: t) {
        int lim;
        if (c == 'B') lim = s - 1;
        else if (c == 'S') lim = g - 1;
        else if (c == 'G') lim = p - 1;
        else if (c == 'P') lim = d - 1;
        else lim = d + pre;
        ans += lim - pre;
        pre = max(0, lim - pre);
    }
    cout << ans << '\n';
}