#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    typedef tuple<int, int, int> ti;
    int n;
    cin >> n;
    vector<tuple<int, int, int>> lhr(n);
    for (auto &[l, h, r]: lhr) cin >> l >> h >> r;
    sort(lhr.begin(), lhr.end(), [](ti &a, ti &b) {
       return make_tuple(get<0>(a), -get<1>(a), get<2>(a)) < make_tuple(get<0>(b), -get<1>(b), get<2>(b));
    });

    vector<pi> ans;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    multiset<int> hs = {0};
    auto chk = [&](int idx, function<void()> blk) {
        int pmx = *prev(hs.end());
        blk();
        int mx = *prev(hs.end());
        if (pmx != mx) ans.emplace_back(idx, mx);
    };

    for (auto [l, h, r]: lhr) {
        while (!pq.empty() && pq.top().first < l) {
            auto [pr, ph] = pq.top();
            pq.pop();
            chk(pr, [&](){ hs.erase(hs.find(ph)); });
        }
        chk(l, [&]() {
            while (!pq.empty() && pq.top().first <= l) {
                auto [pr, ph] = pq.top();
                pq.pop();
                hs.erase(hs.find(ph));
            }
            pq.emplace(r, h);
            hs.insert(h);
        });
    }
    while (!pq.empty()) {
        auto [pr, ph] = pq.top();
        pq.pop();
        chk(pr, [&](){ hs.erase(hs.find(ph)); });
    }

    for (auto [x, h]: ans) cout << x << ' ' << h << ' ';
    cout << '\n';
}