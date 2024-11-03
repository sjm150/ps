#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1 - i; j++) cout << (i <= j ? '*': ' ');
        cout << '\n';
    }
}