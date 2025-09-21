#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int cnt[7] = {};
        for (int i = 0; i < 4; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        vector<pair<int, int>> ord;
        for (int i = 1; i <= 6; i++) {
            if (cnt[i]) ord.emplace_back(cnt[i], i);
        }
        sort(ord.begin(), ord.end());
        if (ord.size() == 1) {
            ans = max(ans, 50000 + ord[0].second * 5000);
        } else if (ord.size() == 2) {
            if (ord.back().first == 3) {
                ans = max(ans, 10000 + ord[1].second * 1000);
            } else {
                ans = max(ans, 2000 + (ord[0].second + ord[1].second) * 500);
            }
        } else if (ord.size() == 3) {
            ans = max(ans, 1000 + ord[2].second * 100);
        } else {
            ans = max(ans, ord[3].second * 100);
        }
    }
    cout << ans << '\n';
}