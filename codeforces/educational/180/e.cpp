#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mx = 5e5;
    vector<int> cnt(mx / 2);
    cnt[0] = 1;
    for (int i = 3; i <= mx; i += 2) {
        cnt[i / 2] = cnt[i / 2 - 1] + 1;
        for (int j = 3; j * j <= i; j++) {
            if (i % j == 0) cnt[i / 2] = min(cnt[i / 2], cnt[j / 2] + cnt[i / j / 2] - 1);
        }
    }

    int t; cin >> t;
    while (t--) {
        int m;
        cin >> m;
        cout << (m % 2 ? cnt[m / 2] : -1) << '\n';
    }
}