#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<bool> ban(n + 1, false);
    int x;
    while (cin >> x) ban[x] = true;

    int cnt = 0;
    for (int i = n; i >= 0; i--) {
        if (ban[i]) {
            cnt++;
        } else {
            if (cnt >= k) n = i;
            cnt = 0;
        }
    }

    int i = n;
    for (; i >= k + 1; i -= k + 1) {
        while (ban[i]) i--;
    }
    while (ban[i]) i--;

    cout << (i == 0 ? 0 : 1) << '\n';
}