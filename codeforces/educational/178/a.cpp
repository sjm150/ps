#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int sum = a + b + c;
        cout << (sum % 3 == 0 && b <= sum / 3 ? "YES\n" : "NO\n");
    }
}