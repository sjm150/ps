#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int cnt[10] = {};
    fill(cnt + 1, cnt + 10, inf);
    for (int i = 0; i < n; i++) {
        int d = t[i] - s[i];
        int nc[10];
        fill(nc, nc + 10, inf);
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                nc[j] = min(nc[j], (j - k + 10) % 10 + (j - d + 10) % 10 + cnt[k]);
            }
        }
        swap(cnt, nc);
    }
    cout << *min_element(cnt, cnt + 10) << '\n';
}