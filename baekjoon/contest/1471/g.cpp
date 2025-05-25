#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int sz = n * 2;
    vector<int> a(sz), b(sz);
    for (int &a: a) {
        char c;
        cin >> c;
        a = c == 'R';
    }
    for (int &b: b) {
        char c;
        cin >> c;
        b = c == 'R';
    }

    auto chk = [&](vector<int> a, vector<int> b, int cnt) {
        int al = 0, ar = sz - 1, bl = 0, br = sz - 1;
        for (int i = 0; i < cnt; i++) {
            while (al < ar && a[al] == 1) al++;
            while (al < ar && a[ar] == 0) ar--;
            while (bl < br && b[bl] == 0) bl++;
            while (bl < br && b[br] == 1) br--;
            if (ar - al > br - bl) swap(a[al], a[ar]);
            else swap(b[bl], b[br]);
        }
        int asum = 0, bsum = 0;
        for (int i = 0; i < sz - 1; i++) {
            asum += a[i];
            bsum += b[i];
            if (asum == bsum) return false;
        }
        return true;
    };

    int l = 0, r = sz + 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (chk(a, b, m) || chk(b, a, m)) r = m;
        else l = m + 1;
    }
    cout << r << '\n';
}