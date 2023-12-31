#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int ocnt = a[0] & 1;
        ll sum = a[0];
        int rsub[] = {0, 1, 0};

        cout << sum << ' ';
        for (int k = 1; k < n; k++) {
            if (a[k] & 1) ocnt++;
            sum += a[k];
            int q = ocnt / 3, r = ocnt % 3;
            cout << sum - q - rsub[r] << ' ';
        }
        cout << '\n';
    }
}