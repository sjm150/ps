#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m, n; cin >> m >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    int ans = 0;
    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n / 2; i++) {
        cnt[a[i]]--;
        cnt[a[i + n / 2] - 1]++;
    }
    for (int i = n / 2; i; i--) {
        bool ok = true;
        int cur = 0;
        for (int j = m; j >= 0; j--) {
            cur += cnt[j];
            if (cur < 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = i;
            break;
        }
        cnt[a[i - 1]]++;
        cnt[a[i - 1] - 1]++;
        cnt[a[i * 2 - 1] - 1]--;
        cnt[a[i * 2 - 2] - 1]--;
    }
    cout << ans << '\n';
}