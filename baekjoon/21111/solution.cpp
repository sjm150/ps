#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mod = 998244353;
    typedef long long ll;
    int n, k; cin >> n >> k;
    string s; cin >> s;
    ll sw = 0, sa = 0, sc = 0, swa = 0, sac = 0, swac = 0;
    for (char c: s) {
        if (c == 'W') {
            sw++;
        } else if (c == 'A') {
            sa++;
            swa = (swa + sw) % mod;
        } else if (c == 'C') {
            sc++;
            sac = (sac + sa) % mod;
            swac = (swac + swa) % mod;
        }
    }
    ll w = 0, wa = 0, wac = 0;
    while (k--) {
        wac = (wac + wa * sc + w * sac + swac) % mod;
        wa = (wa + w * sa + swa) % mod;
        w = (w + sw) % mod;
    }
    cout << wac << '\n';
} 