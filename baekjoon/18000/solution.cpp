#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> x(n), r(k + 1);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        r[x[i]] = i;
    }
    vector<pair<int, int>> rx;
    for (int i = 1; i <= k; i++) rx.emplace_back(r[i], i);
    sort(rx.begin(), rx.end());

    set<int> cand;
    vector<bool> used(k + 1, false);
    vector<queue<int>> q(k + 1);
    auto add = [&](int i) {
        if (used[x[i]]) return;
        if (q[x[i]].empty()) cand.insert(x[i]);
        q[x[i]].push(i);
    };
    auto del = [&](int i) {
        if (used[x[i]]) return;
        q[x[i]].pop();
        if (q[x[i]].empty()) cand.erase(x[i]);
    };

    int l = 0, idx = 0;
    for (int i = 0; i <= rx[0].first; i++) add(i);
    for (int i = 0; i < k; i++) {
        while (idx < k && used[rx[idx].second]) {
            idx++;
            if (idx == n) break;
            for (int i = rx[idx - 1].first + 1; i <= rx[idx].first; i++) add(i);
        }
        int s = *cand.begin();
        int nl = q[s].front();
        while (l <= nl) del(l++);
        used[s] = true;
        cand.erase(s);
        cout << s << ' ';
    }
    cout << '\n';
}