#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int &p: p) cin >> p;

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) pq.emplace(p[i], -i);
    bool ok = true;
    while (k--) {
        auto [p, i] = pq.top();
        pq.pop();
        if (p <= 100) {
            ok = false;
            break;
        }
        pq.emplace(p - 100, i);
    }

    if (ok) {
        while (!pq.empty()) {
            auto [pp, i] = pq.top();
            pq.pop();
            p[-i] = pp;
        }
        for (int p: p) cout << p << ' ';
        cout << '\n';
    } else {
        cout << "impossible\n";
    }
}