#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll a, b; cin >> a >> b;
    cout << a / gcd(a, b) * b << '\n';
}