#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int mx = *max_element(a.begin(), a.end());
        vector<int> cnt(mx + 1, 0);
        for (int a: a) cnt[a]++;
        int ans = 0;
        for (int i = 0; i <= mx; i++) {
            if (cnt[i] < i) ans += cnt[i];
            else if (cnt[i] > i) ans += cnt[i] - i;
        }
        cout << ans << '\n';
    }
}