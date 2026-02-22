#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const double eps = 1e-6;
    int n;
    cin >> n;
    vector<int> h(n);
    for (int &h: h) cin >> h;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        double mx = -h[i];
        for (int j = i - 1; j >= 0; j--) {
            auto x = double(h[j] - h[i]) / (i - j);
            if (x > mx + eps) {
                mx = x;
                cnt++;
            }
        }
        mx = -h[i];
        for (int j = i + 1; j < n; j++) {
            auto x = double(h[j] - h[i]) / (j - i);
            if (x > mx + eps) {
                mx = x;
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}