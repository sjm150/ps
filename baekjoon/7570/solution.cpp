#include <bits/stdc++.h>
using namespace std;

int idx[1000001];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        idx[x] = i;
    }
    int len = 1, maxl = 1;
    for (int i = 2; i <= n; i++) {
        if (idx[i - 1] < idx[i]) {
            len++;
            if (len > maxl) maxl = len;
        } else {
            len = 1;
        }
    }
    cout << n - maxl << '\n';
}