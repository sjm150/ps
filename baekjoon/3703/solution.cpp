#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-5;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, f; cin >> n >> f;
        f++;
        vector<int> v(n);
        for (int &v: v) {
            cin >> v;
            v *= v;
        }

        double l = eps, r = *max_element(v.begin(), v.end()) + 1;
        while (r - l > eps) {
            double m = (l + r) / 2;
            long long cnt = 0;
            for (int v: v) cnt += int(v / m);
            if (cnt >= f) l = m + eps;
            else r = m;
        }

        cout << fixed << setprecision(4) << (r - eps) * M_PI << '\n';
    }
}