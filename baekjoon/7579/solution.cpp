#include <bits/stdc++.h>
using namespace std;

int mem[100], c[100];
int maxm[10001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> mem[i];
    int csum = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        csum += c[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = csum; j >= c[i]; j--) {
            maxm[j] = max(maxm[j], maxm[j - c[i]] + mem[i]);
        }
    }
    for (int i = 0; i <= csum; i++) {
        if (maxm[i] >= m) {
            cout << i << '\n';
            break;
        }
    }
}