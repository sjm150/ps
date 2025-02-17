#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= 2 * n - 1; i++) {
        for (int j = 0; j < n; j++) cout << (j < n - min(i, 2 * n - i) ? ' ' : '*');
        cout << '\n';
    }
}