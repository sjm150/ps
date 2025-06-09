#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n, r, bx, by, bvx, bvy;
    cin >> n >> r >> bx >> by >> bvx >> bvy;

    vector<pair<double, double>> range;
    for (int i = 0; i < n; i++) {
        int x, y, vx, vy;
        cin >> x >> y >> vx >> vy;
        int dx = x - bx, tx = vx - bvx, dy = y - by, ty = vy - bvy;
        ll a = tx * tx + ty * ty, b = dx * tx + dy * ty, c = dx * dx + dy * dy - r * r;
        if (a) {
            if (b * b - a * c < 0) continue;
            double s = sqrt(b * b - a * c);
            double l = (-b - s) / a, r = (-b + s) / a;
            if (r < 0) continue;
            range.emplace_back(max(l, 0.), r);
        } else {
            if (dx * dx + dy * dy <= r * r) range.emplace_back(0, 1e18);
        }
    }
    sort(range.begin(), range.end());

    int ans = 0;
    priority_queue<double, vector<double>, greater<double>> pq;
    for (auto [l, r]: range) {
        while (!pq.empty() && pq.top() < l) pq.pop();
        pq.push(r);
        ans = max(ans, int(pq.size()));
    }
    cout << ans << '\n';
}