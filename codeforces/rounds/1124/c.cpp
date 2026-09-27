#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int l = k - 1, r = n - k;
        ll sum = l <= r ? accumulate(a.begin() + l, a.begin() + r + 1, 0ll) : 0ll;
        if (l > r) swap(l, r);
        else l--, r++;
        for (; 0 <= l; l--, r++) sum += max(a[l], a[r]);
        cout << sum << '\n';
    }
}