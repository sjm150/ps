#include <bits/stdc++.h>
using namespace std;
const int MX = 1000000;

vector<bool> prm;

void init() {
    prm = vector<bool>(MX + 1, true);
    prm[0] = prm[1] = false;
    for (int i = 2; i * i <= MX; i++) {
        if (!prm[i]) continue;
        for (int j = i * i; j <= MX; j += i) prm[j] = false;
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    init();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int cnt = 0;
        for (int i = 2; i <= n / 2; i++) {
            if (prm[i] && prm[n - i]) cnt++;
        }
        cout << cnt << '\n';
    }
}