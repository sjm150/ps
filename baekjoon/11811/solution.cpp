#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int m; cin >> m;
            a[i] |= m;
            a[j] |= m;
        }
    }
    for (int a: a) cout << a << ' ';
    cout << '\n';
}