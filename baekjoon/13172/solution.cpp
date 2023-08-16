#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int modinv(int i) {
    return i <= 1 ? i : mod - ll(mod / i) * modinv(mod % i) % mod;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m; cin >> m;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int n, s; cin >> n >> s;
        sum += ll(s) * modinv(n) % mod;
        if (sum >= mod) sum -= mod;
    }
    cout << sum << '\n';
}