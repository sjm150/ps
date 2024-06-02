#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x, y; cin >> n >> x >> y;
        vector<int> b(x);
        for (int &b: b) cin >> b;
        sort(b.begin(), b.end());

        vector<int> dff;
        auto push = [&](int d) {
            if (d > 2) dff.push_back(d);
        };
        push(b[0] + n - b[x - 1]);
        for (int i = 1; i < x; i++) push(b[i] - b[i - 1]);
        sort(dff.begin(), dff.end(), [](int a, int b) {
            return ll(a - 1) * ((b + 1) / 2 - 1) > ll(b - 1) * ((a + 1) / 2 - 1);
        });

        int cnt = n - 2;
        for (int d: dff) {
            ++d;
            if (y == 0) {
                cnt -= d - 2;
            } else {
                if (y >= d / 2 - 1) {
                    y -= d / 2 - 1;
                } else {
                    d -= 2 * y;
                    if (d > 2) cnt -= d - 2;
                    y = 0;
                }
            }
        };

        cout << cnt << '\n';
    }
}