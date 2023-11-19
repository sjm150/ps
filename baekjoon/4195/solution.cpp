#include <bits/stdc++.h>
using namespace std;

typedef struct Djset {
    map<string, int> idx;
    vector<int> p, sz;

    int getidx(string& s) {
        auto it = idx.find(s);
        if (it != idx.end()) return it->second;
        int i = p.size();
        idx[s] = i;
        p.push_back(i);
        sz.push_back(1);
        return i;
    }

    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    int uni(string& as, string& bs) {
        int a = find(getidx(as));
        int b = find(getidx(bs));
        if (a == b) return sz[a];
        if (sz[a] > sz[b]) {
            sz[a] += sz[b];
            p[b] = a;
            return sz[a];
        } else {
            sz[b] += sz[a];
            p[a] = b;
            return sz[b];
        }
    }
} djs_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int f; cin >> f;
        djs_t djs;
        while (f--) {
            string s1, s2; cin >> s1 >> s2;
            cout << djs.uni(s1, s2) << '\n';
        }
    }
}