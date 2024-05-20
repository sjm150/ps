#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        long long ans = 0;
        map<ti, int> tm;
        vector<map<pi, int>> pms(3);
        for (int i = 0; i < n - 2; i++) {
            auto tit = tm.find(ti(a[i], a[i + 1], a[i + 2]));
            if (tit == tm.end()) tit = tm.emplace(ti(a[i], a[i + 1], a[i + 2]), 0).first;

            pi pis[3] = {pi(a[i], a[i + 1]), pi(a[i], a[i + 2]), pi(a[i + 1], a[i + 2])};
            for (int i = 0; i < 3; i++) {
                auto pit = pms[i].find(pis[i]);
                if (pit == pms[i].end()) pit = pms[i].emplace(pis[i], 0).first;
                ans += pit->second - tit->second;
                pit->second++;
            }

            tit->second++;
        }

        cout << ans << '\n';
    }
}