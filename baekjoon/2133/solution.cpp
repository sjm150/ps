#include <bits/stdc++.h>
using namespace std;

int cnt[31];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    if (n % 2 == 1) {
        cout << 0 << '\n';
    } else {
        cnt[0] = 1, cnt[2] = 3;
        for (int i = 4; i <= n; i += 2) {
            cnt[i] = 3 * cnt[i - 2];
            for (int j = i - 4; j >= 0; j -= 2) cnt[i] += 2 * cnt[j];
        }
        cout << cnt[n] << '\n';
    }
}