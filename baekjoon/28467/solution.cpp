#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    set<int> rem;
    for (int i = -1; i <= n; i++) rem.insert(i);
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });
    ord.pop_back();

    long long ans = 0;
    for (int i: ord) {
        auto it = rem.find(i);
        int l = *prev(it), r = *next(it);
        int j = r == n || (l >= 0 && a[l] < a[r]) ? l : r;
        ans += a[i] + a[j];
        rem.erase(it);
    }
    cout << ans << '\n';
}