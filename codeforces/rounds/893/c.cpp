#include <bits/stdc++.h>
using namespace std;

bool used[100001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        fill(used, used + n + 1, false);
        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;
            cout << i << ' ';
            for (int j = i * 2; j <= n; j *= 2) {
                cout << j << ' ';
                used[j] = true;
            }
        }
        cout << '\n';
    }
}