#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef tuple<long long, int, int> ti;
    int n, k;
    cin >> n >> k;
    vector<int> t(n);
    for (int &t: t) cin >> t;
    sort(t.begin(), t.end());

    priority_queue<ti, vector<ti>, greater<ti>> pq;
    for (int i = 0; i < min(n, k); i++) pq.emplace(t[i], t[i], 5);
    int r = n;
    for (;;) {
        auto [cur, t, c] = pq.top();
        if (c < r) {
            r -= c;
            pq.pop();
            pq.emplace(cur + 2 * t, t, 4);
        } else {
            break;
        }
    }

    cout << get<0>(pq.top()) << '\n';
}