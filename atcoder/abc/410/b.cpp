#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<int> cnt(n, 0), b(q);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x) {
            b[i] = x;
            cnt[x - 1]++;
        } else {
            int idx = min_element(cnt.begin(), cnt.end()) - cnt.begin();
            b[i] = idx + 1;
            cnt[idx]++;
        }
    }
    for (int b: b) cout << b << ' ';
    cout << '\n';
}