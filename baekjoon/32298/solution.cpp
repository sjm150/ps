#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n + 1; i++) cout << i * m << ' ';
    cout << '\n';
}