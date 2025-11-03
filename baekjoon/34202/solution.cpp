#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> c(n - 1);
    for (int &c: c) cin >> c;

    vector<int> gt, lt, eq;
    for (int i = 1; i < n - 1; i++) (c[i - 1] < c[i] ? gt : (c[i - 1] > c[i] ? lt : eq)).push_back(i);

    int sz = gt.size(), eidx = 0, esz = eq.size();
    assert(lt.size() == sz);
    vector<int> p;
    p.push_back(0);
    for (int i = 0; i < sz; i++) {
        for (; eidx < esz && eq[eidx] < lt[i]; eidx++) p.push_back(eq[eidx]);
        p.push_back(lt[i]);
        p.push_back(gt[i]);
    }
    while (eidx < esz) p.push_back(eq[eidx++]);
    p.push_back(n - 1);

    for (int p: p) cout << p + 1 << ' ';
    cout << '\n';
}