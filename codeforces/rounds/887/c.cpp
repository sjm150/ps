#include <iostream>
using namespace std;
typedef long long ll;

int a[200000];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        if (a[0] > 1) {
            cout << 1 << '\n';
            continue;
        }
        ll x = 1;
        int j = 0;
        for (int i = 0; i < k; i++) {
            x += j;
            while (j < n && a[j] <= x) x++, j++;
        }
        cout << x << '\n';
    }
}