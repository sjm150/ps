typedef long long ll;

class Solution {
public:
    int numOfWays(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        auto inv = [](ll x) {
            ll ret = 1;
            for (int i = mod - 2; i; i /= 2) {
                if (i % 2) ret = ret * x % mod;
                x = x * x % mod;
            }
            return ret;
        };

        vector<ll> f(n + 1), fi(n + 1);
        f[0] = fi[0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] * i % mod;
            fi[i] = inv(f[i]);
        }
        auto cmb = [&](int n, int k) {
            return f[n] * fi[k] % mod * fi[n - k] % mod;
        };

        int cnt = 1;
        function<void(vector<int>&)> dfs = [&](vector<int>& a) {
            int sz = a.size();
            if (sz < 2) return;
            vector<int> l, r;
            for (int i = 1; i < sz; i++) (a[i] < a[0] ? l : r).push_back(a[i]);
            int lsz = l.size(), rsz = r.size();
            cnt = cnt * cmb(lsz + rsz, lsz) % mod;
            dfs(l);
            dfs(r);
        };
        dfs(nums);

        return (cnt + mod - 1) % mod;
    }
};