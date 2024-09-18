#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    sort(a.begin(), a.end());
    vector<int> suma(n);
    suma[0] = a[0];
    for (int i = 1; i < n; i++) suma[i] = suma[i - 1] + a[i];
    int ans = a[0], val = suma[n - 1] - n * a[0];
    for (int i = 1; i < n; i++) {
        int v = suma[n - 1] - 2 * suma[i] + (2 * i + 2 - n) * a[i];
        if (val > v) {
            ans = a[i];
            val = v;
        }
    }
    cout << ans << '\n';
}