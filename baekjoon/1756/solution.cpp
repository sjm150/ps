#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int d, n; cin >> d >> n;
    vector<int> r(d + 1);
    r[0] = 0;
    for (int i = d; i >= 1; i--) cin >> r[i];
    for (int i = d - 1; i >= 1; i--) r[i] = min(r[i + 1], r[i]);

    auto it = r.begin();
    while (n--) {
        int x; cin >> x;
        if (it != r.end()) it = lower_bound(next(it), r.end(), x);
    }
    cout << r.end() - it << '\n';
}