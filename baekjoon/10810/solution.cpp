#include <bits/stdc++.h>
using namespace std;

int num[100];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int i, j, k; cin >> i >> j >> k;
        fill(num + i - 1, num + j, k);
    }
    for (int i = 0; i < n; i++) cout << num[i] << ' ';
    cout << '\n';
}