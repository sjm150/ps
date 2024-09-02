#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<bool> isp(mx + 1, true);
    vector<int> phi(mx + 1);
    iota(phi.begin(), phi.end(), 0);
    for (int i = 2; i <= mx; i++) {
        if (!isp[i]) continue;
        for (int j = i; j <= mx; j += i) {
            isp[j] = false;
            phi[j] = phi[j] / i * (i - 1);
        }
    }
    phi[1] = 2;
    for (int i = 2; i <= mx; i++) phi[i] += phi[i - 1];
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << phi[n] << '\n';
    }
}