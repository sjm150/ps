#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct Info {
    ll f, m, p;
    bool operator<(Info &o) { return f * o.m < o.f * m; }
} i_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int f, m, n; cin >> f >> m >> n;
    vector<i_t> infos(n);
    for (int i = 0; i < n; i++) {
        infos[i].p = i + 1;
        cin >> infos[i].f >> infos[i].m;
    }
    sort(infos.begin(), infos.end());

    i_t cur;
    cur.f = f, cur.m = m;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        auto inf = infos[i];
        if (cur < inf) {
            cur.f += inf.f, cur.m += inf.m;
            ans.push_back(inf.p);
        } else {
            break;
        }
    }

    if (ans.empty()) {
        cout << "NONE\n";
    } else {
        sort(ans.begin(), ans.end());
        for (auto a: ans) cout << a << '\n';
    }
}