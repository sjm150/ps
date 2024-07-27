#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mx = 1e8;
    vector<bool> isp(mx + 1, true);
    vector<int> prm;
    for (int i = 2; i <= mx; i++) {
        if (!isp[i]) continue;
        prm.push_back(i);
        for (ll j = ll(i) * i; j <= mx; j += i) isp[j] = false;
    }
    int n;
    while (cin >> n) {
        if (n < 8) {
            cout << "Impossible.\n";
            continue;
        }
        if (n % 2) {
            cout << "2 3 ";
            n -= 5;
        } else {
            cout << "2 2 ";
            n -= 4;
        }
        for (int p: prm) {
            if (isp[n - p]) {
                cout << p << ' ' << n - p << '\n';
                break;
            }
        }
    }
}