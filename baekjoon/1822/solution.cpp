#include <iostream>
#include <algorithm>

using namespace std;

int a[500000], b[500000];
int ans[500000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!binary_search(b, b + m, a[i])) {
            ans[cnt++] = a[i];
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++) cout << ans[i] << ' ';
    cout << '\n';
}