#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int sum = 0;
    vector<int> cnt(m, 0);
    cnt[0] = 1;
    while (n--) {
        int a; cin >> a;
        sum = (sum + a) % m;
        cnt[sum]++;
    }

    ll ans = 0;
    for (int c: cnt) ans += c * ll(c - 1) / 2;
    cout << ans << '\n';
}