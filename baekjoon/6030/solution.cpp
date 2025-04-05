#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int p, q; cin >> p >> q;
    vector<int> fp, fq;
    for (int i = 1; i * i <= p; i++) {
        if (p % i == 0) {
            fp.push_back(i);
            if (i * i != p) fp.push_back(p / i);
        }
    }
    sort(fp.begin(), fp.end());
    for (int i = 1; i * i <= q; i++) {
        if (q % i == 0) {
            fq.push_back(i);
            if (i * i != q) fq.push_back(q / i);
        }
    }
    sort(fq.begin(), fq.end());
    for (int p: fp) {
        for (int q: fq) cout << p << ' ' << q << '\n';
    }
}