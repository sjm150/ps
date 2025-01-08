#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k, m; cin >> n >> k >> m;
    vector<int> ans(k);
    iota(ans.begin(), ans.end(), 1);
    while (m--) {
        for (int a: ans) cout << a << ' ';
        cout << endl;
        int x;
        for (int i = 0; i < n - k; i++) cin >> x;
    }
}