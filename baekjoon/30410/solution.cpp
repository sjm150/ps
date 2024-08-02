#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    vector<pair<int, int>> seq;
    auto add = [&](int a, int len) {
        if (a == 1 && len % 2 == 0) {
            a = 2;
            len /= 2;
        }
        if (!seq.empty() && seq.back().first == a) seq.back().second += len;
        else seq.emplace_back(a, len);
    };

    int len = 1;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] != a[i]) {
            add(a[i - 1], len);
            len = 1;
        } else {
            len++;
        }
    }
    add(a.back(), len);

    int ans = 1;
    int sz = seq.size();
    for (int i = 0; i < sz; i++) {
        int len = seq[i].second;
        if (seq[i].first == 2) {
            if (i > 0) len += seq[i - 1].second / 2;
            if (i < sz - 1) len += seq[i + 1].second / 2;
        }
        int t = 1;
        while (t <= len) t *= 2;
        ans = max(ans, t / 2 * seq[i].first);
    }
    cout << ans << '\n';
}