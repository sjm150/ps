#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    sort(a.begin(), a.end());

    int l = a[0], r = a[1];
    int mx = r - l;
    for (int i = 2; i < n - 1; i++) {
        if (i % 2) {
            mx = max(mx, a[i] - r);
            r = a[i];
        } else {
            mx = max(mx, a[i] - l);
            l = a[i];
        }
    }
    mx = max(mx, max(a[n - 1] - l, a[n - 1] - r));

    vector<int> ans(n);
    ans[0] = a[0];
    l = 1, r = n - 1;
    for (int i = 1; i < n - 1; i++) {
        if (a[i + 1] - ans[(r + 1) % n] > mx) ans[r--] = a[i];
        else ans[l++] = a[i];
    }
    ans[l] = a[n - 1];
    for (int a: ans) cout << a << ' ';
    cout << '\n';
}