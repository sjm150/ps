#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t, n; cin >> t >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    vector<bool> poss(t + 1, false);
    vector<int> lst(t + 1, -1);
    poss[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = t; j >= a[i]; j--) {
            if (poss[j] || !poss[j - a[i]]) continue;
            poss[j] = true;
            lst[j] = i;
        }
    }

    int idx = t;
    while (!poss[idx]) idx--;
    vector<int> g;
    for (; lst[idx] >= 0; idx -= a[lst[idx]]) g.push_back(lst[idx]);

    vector<int> ans(n);
    vector<bool> used(n, false);
    int cur = 0;
    for (int i: g) {
        used[i] = true;
        ans[i] = cur;
        cur += a[i];
    }
    cur = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        ans[i] = cur;
        cur += a[i];
    }

    for (int a: ans) cout << a << ' ';
    cout << '\n';
}