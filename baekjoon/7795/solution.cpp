#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[20000], b[20000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        sort(a, a + n);
        sort(b, b + m);
        int total = 0, idx = 0;
        for (int i = 0; i < n; i++) {
            while (idx < m && a[i] > b[idx]) idx++;
            total += idx;
        }
        cout << total << '\n';
    }
}