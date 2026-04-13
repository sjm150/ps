#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    vector<vector<ll>> cnt(19, vector<ll>(9, 0));
    cnt[0][0] = 1;
    for (int i = 1; i <= 18; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) cnt[i][(j + k) % 9] += cnt[i - 1][k];
        }
    }
    auto getc = [&](ll x) {
        string s = to_string(x);
        ll c = 0, n = s.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            for (int j = 0; j < d; j++) {
                for (int k = 0; k < 9; k++) {
                    if ((sum + j + k) % 9) c += cnt[n - i - 1][k];
                }
            }
            sum += d;
        }
        return c;
    };
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        ll f, l;
        cin >> f >> l;
        cout << "Case #" << tc << ": " << getc(l + 1) - getc(f) << '\n';
    }
}