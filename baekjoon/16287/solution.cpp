#include <bits/stdc++.h>
using namespace std;

const int MX = 800000;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int w, n; cin >> w >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<bool> chk(MX, false);
    bool poss = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int idx = w - a[i] - a[j];
            if (0 <= idx && chk[idx]) {
                poss = true;
                break;
            }
        }
        if (poss) break;
        for (int j = 0; j < i; j++) chk[a[i] + a[j]] = true;
    }

    if (poss) cout << "YES\n";
    else cout << "NO\n";
}