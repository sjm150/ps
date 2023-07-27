#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> a[300000];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        for (int i = 0; i < n; i++) {
            int num; cin >> num;
            num %= k;
            int v = num == 0 ? 0 : k - num;
            a[i] = {v, i + 1};
        }
        sort(a, a + n);
        for (int i = 0; i < n; i++) cout << a[i].second << ' ';
        cout << '\n';
    }
}