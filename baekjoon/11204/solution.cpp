#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<ld>> comb(n + 1, vector<ld>(n + 1, 1));
    for (int i = 1; i <= n; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) comb[i][j] = comb[i][j - 1] / j * (i - j + 1);
    }
    auto pow = [&](ld x, int e) {
        ld res = 1;
        for (; e; e /= 2) {
            if (e % 2) res *= x;
            x *= x;
        }
        return res;
    };
    vector<ld> p(n + 1, 1);
    for (int i = 4; i <= n; i++) {
        for (int j = 2; j < i - 1; j++) p[i] -= p[j] * comb[i - 1][j - 1] * pow(ld(j - 1) / (i - 1), j) * pow(ld(i - j - 1) / (i - 1), i - j);
    }
    cout << fixed << setprecision(9) << p[n] << '\n';
}