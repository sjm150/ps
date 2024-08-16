#include <bits/stdc++.h>
using namespace std;

const int mx = 1e7;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<bool> isp(mx + 1, true);
    vector<int> p;
    for (int i = 2; i <= mx; i++) {
        if (!isp[i]) continue;
        p.push_back(i);
        for (ll j = ll(i) * i; j <= mx; j += i) isp[j] = false;
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int x = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a == 1) {
                x ^= 1;
                continue;
            }
            if (a % 2 == 0) {
                continue;
            }
            int d = 0;
            for (int p: p) {
                if (a < ll(p) * p) {
                    d = a;
                    break;
                }
                if (a % p == 0) {
                    d = p;
                    break;
                }
            }
            x ^= upper_bound(p.begin(), p.end(), d) - p.begin();
        }
        cout << (x ? "Alice\n" : "Bob\n");
    }
}