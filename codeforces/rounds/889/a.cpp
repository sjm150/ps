#include <iostream>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int p; cin >> p;
            if (i == p) cnt++;
        }
        cout << (cnt + 1) / 2 << '\n';
    }
}