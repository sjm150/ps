#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n), p(n);
        for (int &v: v) cin >> v;
        for (int &p: p) cin >> p;

        vector<pi> vo(n);
        for (int i = 0; i < n; i++) vo[i] = {v[p[i] - 1], i + 1};
        sort(vo.begin(), vo.end(), greater<pi>());

        priority_queue<int, vector<int>, greater<int>> pq;
        int idx = 0, maxc = 0;
        ll maxs = 0;
        bool done = false;

        for (int k = 1; k <= n; k++) {
            while (!pq.empty() && pq.top() < k) pq.pop();

            int minv = 2e9;
            while (pq.size() < k) {
                if (idx == n) {
                    done = true;
                    break;
                }
                auto &[v, o] = vo[idx++];
                if (o < k) continue;
                minv = min(minv, v);
                pq.push(o);
            }
            if (done) break;

            if (maxs < ll(minv) * k) {
                maxs = ll(minv) * k;
                maxc = k;
            }
        }

        cout << maxs << ' ' << maxc << '\n';
    }
}