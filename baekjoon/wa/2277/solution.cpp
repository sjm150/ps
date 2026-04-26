#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> num(n);
    for (int i = 0; i < n; i++) cin >> num[i];

    vector<pair<int, int>> cur(n);
    vector<bool> rot(n);
    int cnt, ans = n * m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (num[j] < num[i]) cur[j].first = num[j] + m;
            else cur[j].first = num[j];
            cur[j].second = j;
        }
        sort(cur.begin(), cur.end());
        fill(rot.begin(), rot.end(), false);
        cnt = 1;

        int sum = 0;
        rot[cur[0].second] = true;
        for (int j = 1; j < n; j++) {
            auto &[num, idx] = cur[j];
            sum += (num - cur[j - 1].first) * cnt;
            if (idx > 0 && rot[idx - 1]) cnt--;
            if (idx < n - 1 && rot[idx + 1]) cnt--;
            rot[idx] = true;
            cnt++;
        }
        ans = min(ans, sum);
    }

    cout << ans << '\n';
}