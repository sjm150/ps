#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int cnt = 0;
        for (int a = 1; a < n; a++) {
            for (int b = a + 1; b < n; b++) cnt += (a * a + b * b + m) % (a * b) == 0;
        }
        cout << cnt << '\n';
    }
}