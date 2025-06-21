#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<bool> blk(n, false);
    auto get = [&](int i) {
        if (i < 0 || i >= n) return false;
        return bool(blk[i]);
    };
    int cnt = 0;
    while (q--) {
        int a;
        cin >> a;
        a--;
        if (blk[a]) {
            blk[a] = false;
            if (get(a - 1) && get(a + 1)) cnt++;
            else if (!get(a - 1) && !get(a + 1)) cnt--;
        } else {
            blk[a] = true;
            if (get(a - 1) && get(a + 1)) cnt--;
            else if (!get(a - 1) && !get(a + 1)) cnt++;
        }
        cout << cnt << '\n';
    }
}