#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    sort(a.begin(), a.end());

    int l = 0, r = n / 2 + 1;
    while (l < r) {
        int x = (l + r) / 2;
        bool poss = true;
        for (int i = 0; i < x; i++) {
            if (a[n - 1 - i] + a[n - 2 * x + i] < m) {
                poss = false;
                break;
            }
        }
        if (poss) l = x + 1;
        else r = x;
    }

    cout << r - 1 << '\n';
}