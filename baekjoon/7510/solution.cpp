#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int tc = 1; tc <= n; tc++) {
        int a[3];
        for (int &a: a) cin >> a;
        sort(a, a + 3);
        cout << "Scenario #" << tc << ":\n";
        cout << (a[2] * a[2] == a[0] * a[0] + a[1] * a[1] ? "yes\n" : "no\n");
        cout << '\n';
    }
}