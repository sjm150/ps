#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) cout << (j < min(i, 2 * n - i) || max(i, 2 * n - i) <= j ? '*' : ' ');
        cout << '\n';
    }
}