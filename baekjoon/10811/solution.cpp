#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> num(n + 1);
    iota(num.begin(), num.end(), 0);
    while (m--) {
        int i, j; cin >> i >>  j;
        for (; i < j; i++, j--) {
            num[i] ^= num[j];
            num[j] ^= num[i];
            num[i] ^= num[j];
        }
    }
    for (int i = 1; i <= n; i++) cout << num[i] << ' ';
    cout << '\n';
}