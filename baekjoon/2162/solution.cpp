#include <bits/stdc++.h>
using namespace std;

const int MX = 3000;

typedef struct Vec {
    int x, y;
    Vec operator - (const Vec& rhs) {
        return Vec {x - rhs.x, y - rhs.y};
    }
    bool operator < (const Vec& rhs) {
        if (x == rhs.x) return y < rhs.y;
        return x < rhs.x;
    }
} vec_t;
typedef struct Line {
    vec_t a, b;
    vec_t min() {
        if (a < b) return a;
        else return b;
    }
    vec_t max() {
        if (a < b) return b;
        else return a;
    }
} line_t;

int ccw(vec_t a, vec_t b) {
    int val = a.x * b.y - a.y * b.x;
    if (val > 0) return 1;
    else if (val < 0) return -1;
    else return 0;
}

bool crosses(line_t& l, line_t& k) {
    int res1 = ccw(l.a - l.b, k.a - l.b) * ccw(l.a - l.b, k.b - l.b);
    int res2 = ccw(k.a - k.b, l.a - k.b) * ccw(k.a - k.b, l.b - k.b);
    if (res1 == 0 && res2 == 0) return !(l.max() < k.min() || k.max() < l.min());
    return res1 <= 0 && res2 <= 0;
}

typedef struct Disjoint {
    int p[MX], sz[MX];
    int scnt, maxs;
    void init(int n) {
        iota(p, p + n, 0);
        fill(sz, sz + n, 1);
        scnt = n;
        maxs = 1;
    }
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    bool uni(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) {
            p[a] = b;
            sz[b] += sz[a];
            maxs = max(maxs, sz[b]);
        } else {
            p[b] = a;
            sz[a] += sz[b];
            maxs = max(maxs, sz[a]);
        }
        scnt--;
        return true;
    }
} dsj_t;

line_t lines[MX];
dsj_t ds;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> lines[i].a.x >> lines[i].a.y >> lines[i].b.x >> lines[i].b.y;
    ds.init(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (crosses(lines[i], lines[j])) ds.uni(i, j);
        }
    }
    cout << ds.scnt << '\n';
    cout << ds.maxs << '\n';
}