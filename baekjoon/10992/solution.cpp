#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= n - 1 + i; j++) cout << (abs(n - 1 - j) == i ? '*' : ' ');
        cout << '\n';
    }
    for (int i = 0; i < 2 * n - 1; i++) cout << '*';
    cout << '\n';
}