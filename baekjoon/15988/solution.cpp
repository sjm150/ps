#include <iostream>
using namespace std;
const int mod = 1000000009;

int cnt[1000001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cnt[1] = 1, cnt[2] = 2, cnt[3] = 4;
    for (int i = 4; i <= 1000000; i++) {
        cnt[i] = cnt[i - 1] + cnt[i - 2];
        if (cnt[i] >= mod) cnt[i] -= mod;
        cnt[i] += cnt[i - 3];
        if (cnt[i] >= mod) cnt[i] -= mod;
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << cnt[n] << '\n';
    }
}