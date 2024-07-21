#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

typedef struct Bitree {
    vector<int> val;
    Bitree(int n): val(n + 1, 0) {}
    void add(int i, int x) {
        i++;
        while (i < val.size()) {
            val[i] = (val[i] + x) % mod;
            i += i & -i;
        }
    }
    int get(int i) {
        i++;
        int ret = 0;
        while (i) {
            ret = (ret + val[i]) % mod;
            i &= i - 1;
        }
        return ret;
    }
} bit_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    vector<bit_t> bits(k + 1, n + 1);
    bits[0].add(0, 1);
    for (int a: a) {
        for (int i = k; i; i--) bits[i].add(a, bits[i - 1].get(a - 1));
    }
    cout << bits[k].get(n) << '\n';
}