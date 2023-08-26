#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1001], b[1001];
int asum[500500], bsum[500500];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t, n, m; cin >> t >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        b[i] += b[i - 1];
    }
    int aidx = 0, bidx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            asum[aidx++] = a[j] - a[i - 1];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            bsum[bidx++] = b[j] - b[i - 1];
        }
    }
    ll cnt = 0;
    sort(asum, asum + aidx);
    for (int i = 0; i < bidx; i++) {
        cnt += upper_bound(asum, asum + aidx, t - bsum[i]) - lower_bound(asum, asum + aidx, t - bsum[i]);
    }
    cout << cnt << '\n';
}