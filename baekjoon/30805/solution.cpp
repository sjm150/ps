#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    auto cmp = [](pi &a, pi &b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    };
    int n; cin >> n;
    vector<pi> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), cmp);
    int m; cin >> m;
    vector<pi> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b.begin(), b.end(), cmp);

    vector<int> ans;
    int ai = 0, bi = 0;
    int al = -1, bl = -1;
    while (ai < n && bi < m) {
        while (ai < n && bi < m && a[ai].first != b[bi].first) {
            if (a[ai].first > b[bi].first) ai++;
            else bi++;
        }
        if (ai < n && bi < m) {
            if (al > a[ai].second) {
                ai++;
            } else if (bl > b[bi].second) {
                bi++;
            } else {
                ans.push_back(a[ai].first);
                al = a[ai++].second;
                bl = b[bi++].second;
            }
        }
    }

    cout << ans.size() << '\n';
    for (int a: ans) cout << a << ' ';
    cout << '\n';
}