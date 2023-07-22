#include <iostream>
#include <algorithm>

using namespace std;

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
        sort(a, a + n);
        int len = 1;
        int maxlen = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] <= k) {
                len++;
            } else {
                maxlen = max(maxlen, len);
                len = 1;
            }
        }
        maxlen = max(maxlen, len);
        cout << n - maxlen << '\n';
    }
}