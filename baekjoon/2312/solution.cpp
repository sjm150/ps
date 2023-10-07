#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 100000;

vector<int> prms;

void init() {
    vector<bool> prm(MX + 1, true);
    for (int i = 2; i <= MX; i++) {
        if (!prm[i]) continue;
        prms.push_back(i);
        for (ll j = ll(i) * i; j <= MX; j += i) prm[j] = false;
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    init();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int p: prms) {
            if (n == 1) break;
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                cnt++;
            }
            if (cnt) cout << p << ' ' << cnt << '\n';
        }
    }
}