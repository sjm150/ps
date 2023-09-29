#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct BiTree {
    vector<ll> val;
    BiTree(int n) {
        val = vector<ll>(n + 1, 0);
    }
    void add(int idx, ll x) {
        idx++;
        while (idx < val.size()) {
            val[idx] += x;
            idx += (idx & -idx);
        }
    }
    ll get(int idx) {
        idx++;
        ll v = 0;
        while (idx) {
            v += val[idx];
            idx &= idx - 1;
        }
        return v;
    }
} bit_t;

ll nums[1000001];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    bit_t bit = BiTree(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        bit.add(i, nums[i]);
    }
    m += k;
    while (m--) {
        ll a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            bit.add(b, c - nums[b]);
            nums[b] = c;
        } else {
            cout << bit.get(c) - bit.get(b - 1) << '\n';
        }
    }
}