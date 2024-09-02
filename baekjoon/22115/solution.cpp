#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> c(n);
    for (int &c: c) cin >> c;
    vector<int> cnt(k + 1, 1e9);
    cnt[0] = 0;
    for (int c: c) {
        for (int i = k; i >= c; i--) cnt[i] = min(cnt[i], cnt[i - c] + 1);
    }
    cout << (cnt[k] < inf ? cnt[k] : -1) << '\n';
}