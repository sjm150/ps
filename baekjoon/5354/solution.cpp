#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 1) {
            cout << "#\n\n";
            continue;
        }
        for (int i = 0; i < n; i++) cout << '#';
        cout << '\n';
        for (int i = 0; i < n - 2; i++) {
            cout << '#';
            for (int j = 0; j < n - 2; j++) cout << 'J';
            cout << "#\n";
        }
        for (int i = 0; i < n; i++) cout << '#';
        cout << "\n\n";
    }
}