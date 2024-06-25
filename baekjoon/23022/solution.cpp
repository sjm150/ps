#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, s; cin >> n >> s;
        vector<pi> tv(n);
        for (auto &[t, v]: tv) cin >> t;
        for (auto &[t, v]: tv) cin >> v;
        sort(tv.begin(), tv.end());

        priority_queue<pi> pq;
        ll ans = 0;
        int idx = 0;
        auto push = [&]() {
            while (idx < n && tv[idx].first <= s) {
                pq.emplace(tv[idx].second, tv[idx].first);
                idx++;
            }
        };
        push();
        while (!pq.empty()) {
            auto [v, t] = pq.top(); pq.pop();
            ans += ll(s - t) * v;
            s++;
            push();
            if (pq.empty() && idx < n) {
                s = tv[idx].first;
                push();
            }
        }

        cout << ans << '\n';
    }
}