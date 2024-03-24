#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, d, k, c; cin >> n >> d >> k >> c;
    vector<int> s(n);
    for (int &s: s) cin >> s;

    vector<int> cnt(d + 1, 0);
    cnt[c] = 1;
    int knd = 1;
    queue<int> q;
    int ans = 1;

    auto iter = [&](int s) {
        q.push(s);
        if (cnt[s] == 0) knd++;
        cnt[s]++;
        if (q.size() > k) {
            int f = q.front(); q.pop();
            cnt[f]--;
            if (cnt[f] == 0) knd--;
        }
        ans = max(ans, knd);
    };

    for (int s: s) iter(s);
    for (int i = 0; i < k; i++) iter(s[i]);

    cout << ans << '\n';
}