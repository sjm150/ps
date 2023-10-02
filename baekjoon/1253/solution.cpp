#include <bits/stdc++.h>
using namespace std;

int a[2000];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1;
        while (l < r) {
            if (l == i) {
                l++;
                continue;
            } else if (r == i) {
                r--;
                continue;
            }
            int sum = a[l] + a[r];
            if (sum < a[i]) {
                l++;
            } else if (sum > a[i]) {
                r--;
            } else {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << '\n';
}