#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    if (n < 8) {
        cout << -1 << '\n';
        return 0;
    }
    if (n % 2) {
        cout << "2 3 ";
        n -= 5;
    } else {
        cout << "2 2 ";
        n -= 4;
    }

    vector<bool> isp(n + 1, true);
    vector<int> prm;
    for (int i = 2; i <= n; i++) {
        if (!isp[i]) continue;
        prm.push_back(i);
        for (ll j = ll(i) * i; j <= n; j += i) isp[j] = false;
    }
    for (int p: prm) {
        if (isp[n - p]) {
            cout << p << ' ' << n - p << '\n';
            break;
        }
    }
}