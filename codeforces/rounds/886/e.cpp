#include <iostream>
using namespace std;
typedef long long ll;

int s[200000];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll c;
        cin >> n >> c;
        for (int i = 0; i < n; i++) cin >> s[i];
        int st = 1, en = 1e9;
        while (st <= en) {
            ll m = (st + en) / 2;
            ll v = 0;
            for (int i = 0; i < n; i++) {
                ll len = s[i] + 2 * m;
                v += len * len;
                if (v > c) break;
            }
            if (v == c) {
                cout << m << '\n';
                break;
            } else if (v < c) {
                st = m + 1;
            } else {
                en = m - 1;
            }
        }
    }
}