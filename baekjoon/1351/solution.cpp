#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll n, p, q;
unordered_map<ll, ll> cache;
ll get(ll i) {
    if (cache.find(i) == cache.end()) cache[i] = get(i / p) + get(i / q);
    return cache[i];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> p >> q;
    cache[0] = 1;
    cout << get(n) << '\n';
}