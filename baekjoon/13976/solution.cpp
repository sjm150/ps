#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<pair<ll, ll>, pair<ll, ll>> mat;
const ll mod = 1e9 + 7;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll n; cin >> n;
    if (n % 2) {
        cout << 0 << '\n';
        return 0;
    }
    auto mul = [](mat &a, mat &b) {
        return make_pair(make_pair((a.X.X * b.X.X + a.X.Y * b.Y.X) % mod, (a.X.X * b.X.Y + a.X.Y * b.Y.Y) % mod), make_pair((a.Y.X * b.X.X + a.Y.Y * b.Y.X) % mod, (a.Y.X * b.X.Y + a.Y.Y * b.Y.Y) % mod));
    };
    n /= 2;
    mat r = {{1, 0}, {0, 1}};
    for (mat m = {{3, 1}, {2, 1}}; n; n /= 2) {
        if (n % 2) r = mul(r, m);
        m = mul(m, m);
    }
    cout << r.X.X << '\n';
}