#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int sz = 1 << n;
    vector<int> a(sz);
    for (int &a: a) cin >> a;
    auto ord = a;
    sort(ord.begin(), ord.end());
    for (int a: a) {
        int cnt = upper_bound(ord.begin(), ord.end(), a) - ord.begin();
        int ans = n + 1;
        for (; cnt; cnt /= 2) ans--;
        cout << ans << ' ';
    }
    cout << '\n';
}