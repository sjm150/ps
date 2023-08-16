#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

unordered_map<ll, ll> fib;
ll get_fib(ll n) {
    if (fib.find(n) != fib.end()) return fib[n];
    ll k = (n + 1) / 2;
    fib[n] = (get_fib(k) * get_fib(n - k + 1) + get_fib(k - 1) * get_fib(n - k)) % mod;
    return fib[n];
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll n; cin >> n;
    fib[0] = 0, fib[1] = 1, fib[2] = 1;
    cout << get_fib(n) << '\n';
}