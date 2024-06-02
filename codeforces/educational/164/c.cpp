#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string x, y; cin >> x >> y;
        if (x.size() < y.size()) swap(x, y);

        int cmp = x.size() > y.size();
        int ofs = x.size() - y.size();
        for (int i = 0; i < y.size(); i++) {
            if (cmp > 0) {
                if (x[ofs + i] > y[i]) swap(x[ofs + i], y[i]);
            } else if (cmp < 0) {
                if (x[ofs + i] < y[i]) swap(x[ofs + i], y[i]);
            } else {
                if (x[ofs + i] > y[i]) cmp = 1;
                else if (x[ofs + i] < y[i]) cmp = -1;
            }
        }

        cout << x << '\n';
        cout << y << '\n';
    }
}