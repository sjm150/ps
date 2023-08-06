#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        for (int i = 1; i <= n + 1; i++) {
            if (n % i != 0) {
                cout << i - 1 << '\n';
                break;
            }
        }
    }
}