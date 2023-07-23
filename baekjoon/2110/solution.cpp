#include <iostream>
#include <algorithm>
using namespace std;

int x[200000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x, x + n);
    int s = 0, e = x[n - 1] + 1;
    while (s < e) {
        int m = (s + e) / 2;
        int pre = 0;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (x[i] - x[pre] >= m) {
                pre = i;
                cnt++;
            }
        }
        if (cnt >= c) s = m + 1;
        else e = m;
    }
    cout << e - 1 << '\n';
}