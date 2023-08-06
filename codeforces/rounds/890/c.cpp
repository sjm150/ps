#include <iostream>
using namespace std;
typedef long long ll;

int a[1000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int maxa = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            maxa = max(maxa, a[i]);
        }
        int s = 0, e = maxa + k + 1;
        while (s < e) {
            int x = (s + e) / 2;
            bool able = false;
            for (int i = 0; i < n - 1; i++) {
                int r = k;
                bool curr = false;
                for (int j = i; j < n - 1; j++) {
                    r -= max(0, x - j + i - a[j]);
                    if (r < 0) break;
                    if (a[j + 1] >= x - j + i - 1) {
                        curr = true;
                        break;
                    }
                }
                if (curr) {
                    able = true;
                    break;
                }
            }
            if (able) s = x + 1;
            else e = x;
        }
        cout << max(e - 1, maxa) << '\n';
    }
}