#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int sz = 20;
    vector<int> c(sz);
    iota(c.begin(), c.end(), 1);
    for (int i = 0; i < 10; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        while (a < b) swap(c[a++], c[b--]);
    }
    for (int c: c) cout << c << ' ';
    cout << '\n';
}