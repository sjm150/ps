#include <bits/stdc++.h>
using namespace std;

int p[1001], sum[1001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            sum[j] = max(sum[j], sum[j - i] + p[i]);
        }
    }
    cout << sum[n] << '\n';
}