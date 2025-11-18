#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    auto query = [&](vector<int> &p) {
        cout << "? ";
        for (int p: p) cout << p << ' ';
        cout << endl;
        vector<int> r(n);
        for (int &r: r) cin >> r;
        return r;
    };

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto r1 = query(p);

    int mxb = 0;
    while ((1 << mxb) < n) mxb++;
    for (int &p: p) p = ((1 << mxb) - 1) - p;
    for (int b = mxb - 1; b >= 0; b--) {
        int cnt = 0;
        for (int i = 0; i < n; i++) cnt -= (i >> b) & 1;
        for (int p: p) cnt += (p >> b) & 1;
        int v = 1 << b;
        for (int i = 0; i < cnt; i++) p[i] -= v;
    }

    auto r2 = query(p);

    cout << "! ";
    for (int i = 0; i < n; i++) cout << ((r1[i] - i) | (r2[i] - p[i])) << ' ';
    cout << endl;
}