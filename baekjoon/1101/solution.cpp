#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<bool> only(m, false);
    int ans = n;
    for (int i = 0; i < n; i++) {
        int k = 0, lst = 0;
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            if (x) {
                k++;
                lst = j;
            }
        }
        if (k == 0) {
            ans--;
        } else if (k == 1 && !only[lst]) {
            only[lst] = true;
            ans--;
        }
    }
    if (ans) ans--;
    cout << ans << '\n';
}