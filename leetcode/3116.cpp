typedef long long ll;

class Solution {
private:
    ll gcd(ll a, ll b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size(), mx = 1 << n;
    
        vector<ll> prd(mx, 1);
        vector<int> bc(mx, 0);
        for (int i = 1; i < mx; i++) {
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) prd[i] *= coins[j] / gcd(prd[i], coins[j]), bc[i]++;
            }
        }

        ll l = 1, r = *max_element(coins.begin(), coins.end()) * ll(k);
        while (l < r) {
            ll m = (l + r) / 2, cnt = 0;
            for (int i = 1; i < mx; i++) cnt += m / prd[i] * (bc[i] % 2 ? 1 : -1);
            if (cnt < k) l = m + 1;
            else r = m;
        }

        return r;
    }
};