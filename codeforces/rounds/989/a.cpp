#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        for (int i = min(a, b); ; i++) {
            if (i % a == i % b) {
                cout << i << '\n';
                break;
            }
        }
    }
}