#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<pi> send[2001];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, c, m; cin >> n >> c >> m;
    while (m--) {
        int from, to, amt;
        cin >> from >> to >> amt;
        send[from].emplace_back(to, amt);
    }
    map<int, int> delv;
    int cur = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        auto it = delv.begin();
        while (it != delv.end() && it->first == i) {
            ans += it->second;
            cur -= it->second;
            it = delv.erase(it);
        }
        sort(send[i].begin(), send[i].end());
        for (auto [to, amt]: send[i]) {
            int exd = max(0, cur + amt - c);
            while (!delv.empty() && exd) {
                auto it = prev(delv.end());
                if (it->first <= to) break;
                if (it->second <= exd) {
                    exd -= it->second;
                    cur -= it->second;
                    it = delv.erase(it);
                } else {
                    cur -= exd;
                    it->second -= exd;
                    exd = 0;
                }
            }
            auto it = delv.find(to);
            int rem = min(c - cur, amt);
            cur += rem;
            if (it == delv.end()) delv.emplace(to, rem);
            else it->second += rem;
        }
    }
    cout << ans << '\n';
}