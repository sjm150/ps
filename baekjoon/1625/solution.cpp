#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef unsigned long long ull;
    typedef struct Bitset {
        ull v[4] = {};
        void set(int i) {
            v[i / 64] |= ull(1) << (i % 64);
        }
        bool get(int i) {
            return (v[i / 64] >> (i % 64)) & 1;
        }
        bool operator<(Bitset &o) {
            for (int i = 0; i < 4; i++) {
                if (v[i] != o.v[i]) return v[i] < o.v[i];
            }
            return false;
        }
        bool operator==(Bitset &o) {
            for (int i = 0; i < 4; i++) {
                if (v[i] != o.v[i]) return false;
            }
            return true;
        }
        bool operator!=(Bitset &o) {
            return !((*this) == o);
        }
        Bitset operator^(Bitset &o) {
            Bitset res;
            for (int i = 0; i < 4; i++) res.v[i] = v[i] ^ o.v[i];
            return res;
        }
    } bs_t;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b = a;
    for (auto &a: a) {
        for (int &a: a) cin >> a;
    }
    for (auto &b: b) {
        for (int &b: b) cin >> b;
    }

    vector<bs_t> aa(m), bb(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) aa[j].set(i);
            if (b[i][j]) bb[j].set(i);
        }
    }

    auto bbs = bb;
    sort(bbs.begin(), bbs.end());

    auto getx = [&]() {
        for (auto &b: bbs) {
            auto x = aa[0] ^ b;
            auto aas = aa;
            for (auto &a: aas) a = a ^ x;
            sort(aas.begin(), aas.end());

            bool ok = true;
            for (int i = 0; i < m; i++) {
                if (aas[i] != bbs[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) return make_pair(true, x);
        }
        return make_pair(false, bs_t());
    };
    auto [res, x] = getx();

    if (res) {
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (x.get(i)) ans.push_back({0, i + 1});
        }
        for (auto &a: aa) a = a ^ x;

        for (int i = 0; i < m; i++) {
            if (aa[i] == bb[i]) continue;
            for (int j = i + 1; j < m; j++) {
                if (aa[j] == bb[i]) {
                    ans.push_back({1, i + 1, j + 1});
                    swap(aa[i], aa[j]);
                    break;
                }
            }
        }

        cout << ans.size() << '\n';
        for (auto &a: ans) {
            for (int a: a) cout << a << ' ';
            cout << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
}