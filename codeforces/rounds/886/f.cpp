#include <iostream>
#include <algorithm>
using namespace std;

int cnt[200001];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i <= n; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a > n) continue;
            cnt[a]++;
        }
        for (int i = (n + 1) / 2; i >= 1; i--) {
            for (int j = 2 * i; j <= n; j += i) cnt[j] += cnt[i];
        }
        int maxcnt = 0;
        for (int i = 1; i <= n; i++) maxcnt = max(maxcnt, cnt[i]);
        cout << maxcnt << '\n';
    }
}