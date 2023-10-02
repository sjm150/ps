#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 * 2 + 1;

int a[100000];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int minv = inf;
    for (int i = 0; i < n; i++) {
        int j = lower_bound(a, a + n, -a[i]) - a;
        if (i != j - 1 && j > 0 && abs(a[i] + a[j - 1]) < abs(minv)) minv = a[i] + a[j - 1];
        if (i != j && j < n - 1 && abs(a[i] + a[j]) < abs(minv)) minv = a[i] + a[j];
    }
    cout << minv << '\n';
}