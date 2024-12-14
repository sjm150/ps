#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mx = 1e5;
    int n; cin >> n;
    vector<int> cnt(mx + 2, 0);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }
    int s = 1, e = mx;
    while (!cnt[s]) s++;
    while (!cnt[e]) e--;
    bool ok = true;
    for (int i = s; i < e - 1; i++) {
        if (cnt[i] >= cnt[i + 1]) {
            ok = false;
            break;
        }
        cnt[i + 1] -= cnt[i];
        cnt[i] = 0;
    }
    cout << (ok && cnt[e - 1] == cnt[e] ? 1 : -1) << '\n';
}