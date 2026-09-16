const int mod = 1e9 + 7;
typedef long long ll;

class Solution {
public:
    int numberOfSets(int n, int k) {
        auto inv = [&](ll x) {
            ll ret = 1;
            for (ll i = mod - 2; i; i /= 2) {
                if (i % 2) ret = ret * x % mod;
                x = x * x % mod;
            }
            return ret;
        };
        ll p = 1, d = 1;
        for (int i = 0; i < 2 * k; i++) {
            p = p * (n + k - 1 - i) % mod;
            d = d * (i + 1) % mod;
        }
        return p * inv(d) % mod;
    }
};