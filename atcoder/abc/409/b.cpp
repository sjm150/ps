#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    sort(a.begin(), a.end());
    auto solve = [&]() {
        int l = 0, r = n + 1;
        while (l < r) {
            int m = (l + r) / 2;
            int cnt = a.end() - lower_bound(a.begin(), a.end(), m);
            if (cnt < m) r = m;
            else l = m + 1;
        }
        return r - 1;
    };
    cout << solve() << '\n';
}