#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    int cnt = 0;
    while (c.back() == 0) c.pop_back();
    cnt += n - c.size();
    n = c.size();

    ll sum = 0;
    for (ll ci: c) {
        if (ci) {
            sum += ci + (cnt + 1) / 2;
            cnt = 0;
        } else {
            cnt++;
        }
    }
    if (n) sum += (cnt + 1) / 2;
    else sum += cnt / 2;

    cout << sum << '\n';
}