#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int a[4000], b[4000], c[4000], d[4000];
int cd[16000000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cd[idx++] = c[i] + d[j];
        }
    }
    sort(cd, cd + idx);
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v = a[i] + b[j];
            cnt += upper_bound(cd, cd + idx, -v) - lower_bound(cd, cd + idx, -v);
        }
    }
    cout << cnt << '\n';
}