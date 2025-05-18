#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n, k;
    cin >> n >> k;

    vector<ll> ans(n + 2, 0), hv = ans;
    while (k--) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        a--, b--;

        if (c == 'R') {
            ans[a]++;
            ans[b + 1]--;
        } else if (c == 'D') {
            ans[a]--;
            ans[b + 1]++;
        } else if (c == 'H') {
            hv[a]++;
            hv[(a + b) / 2 + 1]--;
            hv[(a + b + 1) / 2 + 1]--;
            hv[b + 2]++;
        } else {
            hv[a]--;
            hv[(a + b) / 2 + 1]++;
            hv[(a + b + 1) / 2 + 1]++;
            hv[b + 2]--;
        }
    }

    for (int i = 1; i <= n; i++) hv[i] += hv[i - 1];
    ans[0] += hv[0];
    for (int i = 1; i <= n; i++) ans[i] += ans[i - 1] + hv[i];
    ans.resize(n);
    for (ll a: ans) cout << a << '\n';
}