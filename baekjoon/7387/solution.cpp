#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<pair<int, int>> wh(6);
    for (auto &[w, h]: wh) {
        cin >> w >> h;
        if (w > h) swap(w, h);
    }
    sort(wh.begin(), wh.end());
    bool ok = true;
    for (int i = 0; i < 3; i++) {
        if (wh[i * 2] != wh[i * 2 + 1]) {
            ok = false;
            break;
        }
    }
    if (wh[0].first != wh[2].first || wh[0].second != wh[4].first || wh[2].second != wh[4].second) ok = false;
    cout << (ok ? "POSSIBLE\n" : "IMPOSSIBLE\n");
}