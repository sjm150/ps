#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int sum = 0, qcnt = 0;
    while (n--) {
        int h; cin >> h;
        sum += h;
        qcnt += h / 2;
    }
    if (sum % 3 == 0 && qcnt >= sum / 3) cout << "YES\n";
    else cout << "NO\n";
}