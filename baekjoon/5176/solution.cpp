#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int p, m;
        cin >> p >> m;
        vector<bool> used(m, false);
        for (int i = 0; i < p; i++) {
            int x;
            cin >> x;
            used[x - 1] = true;
        }
        cout << p - accumulate(used.begin(), used.end(), 0) << '\n';
    }
}