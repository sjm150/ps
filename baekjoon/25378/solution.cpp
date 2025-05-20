#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    vector<pi> p;
    for (int i = 0; i < n; i++) {
        int r = a[i];
        for (int j = i + 1; j < n; j++) {
            if (r > a[j]) {
                break;
            } else if (r < a[j]) {
                r = a[j] - r;
            } else {
                p.emplace_back(i, j);
                break;
            }
        }
    }
    sort(p.begin(), p.end(), [](pi &a, pi &b) { return a.second < b.second; });

    int ans = n, lst = -1;
    for (auto [s, e]: p) {
        if (lst < s) {
            ans--;
            lst = e;
        }
    }
    cout << ans << '\n';
}