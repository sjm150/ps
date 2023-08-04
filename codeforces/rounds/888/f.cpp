#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;

int a[200000];
pi p[200000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            p[i] = {a[i], i + 1};
        }
        sort(p, p + n);
        int maxn = INT32_MAX;
        int maxi, maxj;
        for (int i = 1; i < n; i++) {
            if ((p[i - 1].first ^ p[i].first) < maxn) {
                maxn = p[i - 1].first ^ p[i].first;
                maxi = p[i - 1].second;
                maxj = p[i].second;
            }
        }
        cout << min(maxi, maxj) << ' ' << max(maxi, maxj) << ' ' << ((-1 ^ (a[maxi - 1] & a[maxj - 1])) & ((1 << k) - 1)) << '\n';
    }
}