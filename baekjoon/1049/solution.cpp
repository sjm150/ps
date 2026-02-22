#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int mnp = 10000, mns = 10000;
    while (m--) {
        int p, s;
        cin >> p >> s;
        mnp = min(mnp, p), mns = min(mns, s);
    }
    cout << min(n / 6 * mnp + n % 6 * mns, min((n + 5) / 6 * mnp, n * mns)) << '\n';
}