#include <iostream>
using namespace std;
typedef long long ll;

int a[100001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        a[n] = ll(n) * (n + 1) / 2 - sum;
        int i = ((-k) % (n + 1) + n + 1) % (n + 1);
        int cnt = n;
        while (cnt--) {
            cout << a[i] << ' ';
            i++;
            if (i > n) i = 0;
        }
        cout << '\n';
    }
}