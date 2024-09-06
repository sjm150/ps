#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, d; cin >> n >> d;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    map<int, int> cnt;
    for (int a: a) cnt[a / d]++;
    ll ans = 0;
    for (auto &[q, c]: cnt) ans += c * ll(c - 1) / 2;
    cout << ans << '\n';
}