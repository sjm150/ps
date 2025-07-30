#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    vector<pair<int, int>> ord(n);
    for (int i = 0; i < n; i++) ord[i] = {a[i], i};
    sort(ord.begin(), ord.end());

    vector<bool> use(n, false);
    int pre = ord[0].first;
    ll cnt = 0, ans = 0;
    for (auto [a, i]: ord) {
        ans += cnt * (a - pre);
        use[i] = true;
        cnt++;
        if (0 < i && use[i - 1]) cnt--;
        if (i < n - 1 && use[i + 1]) cnt--;
        pre = a;
    }

    cout << ans << '\n';
}