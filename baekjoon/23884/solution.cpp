#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<pair<int, int>> ord(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        ord[i] = {a, i};
    }
    sort(ord.begin(), ord.end());

    vector<int> idx(n), val(n);
    for (int i = 0; i < n; i++) {
        idx[i] = ord[i].second;
        val[ord[i].second] = i;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (idx[i] == i) continue;
        swap(idx[i], idx[val[i]]);
        swap(val[idx[i]], val[idx[val[i]]]);
        k--;
        if (k == 0) break;
    }

    if (k == 0) {
        for (int v: val) cout << ord[v].first << ' ';
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}