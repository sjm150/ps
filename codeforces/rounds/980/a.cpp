#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> a(n);
        for (auto &[a1, a2]: a) cin >> a1 >> a2;
        sort(a.begin(), a.end(), [](pair<int, int> &a, pair<int, int> &b) {
            int mna = min(a.first, a.second), mnb = min(b.first, b.second);
            int mxa = max(a.first, a.second), mxb = max(b.first, b.second);
            if (mna == mnb) return mxa < mxb;
            else return mna < mnb;
        });
        for (auto [a1, a2]: a) cout << a1 << ' ' << a2 << ' ';
        cout << '\n';
    }
}