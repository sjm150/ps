#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int cnt1 = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a == 1) cnt1++;
            sum += a - 1;
        }
        if (n == 1 || cnt1 > sum) cout << "NO\n";
        else cout << "YES\n";
    }
}