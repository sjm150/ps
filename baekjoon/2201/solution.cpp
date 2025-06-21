#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    ll k;
    cin >> k;

    vector<ll> ord = {0, 1, 2};
    while (ord.back() <= k) ord.push_back(ord.back() + ord[ord.size() - 2]);
    ord.pop_back();

    int sz = ord.size();
    string ans(sz, '0');
    for (int i = sz - 1; i > 0; i--) {
        if (ord[i] <= k) {
            ans[i] = '1';
            k -= ord[i];
            i--;
        }
    }
    reverse(ans.begin(), ans.end());
    ans.pop_back();
    cout << ans << '\n';
}