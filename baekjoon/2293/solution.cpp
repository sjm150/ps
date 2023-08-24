#include <bits/stdc++.h>
using namespace std;

int v[100], cnt[10001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> v[i];
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k - v[i]; j++) {
            cnt[j + v[i]] += cnt[j];
        }
    }
    cout << cnt[k] << '\n';
}