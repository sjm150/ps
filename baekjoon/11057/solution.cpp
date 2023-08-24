#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int cnt[10];
    fill(cnt, cnt + 10, 1);
    n--;
    while (n--) {
        for (int i = 9; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                cnt[i] += cnt[j];
                if (cnt[i] >= mod) cnt[i] -= mod;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < 10; i++) sum += cnt[i];
    cout << sum % mod << '\n';
}