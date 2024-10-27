#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    ll a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    cout << max(0ll, b - a - 1) << '\n';
    for (ll i = a + 1; i < b; i++) cout << i << ' ';
    cout << '\n';
}