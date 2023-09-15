#include <bits/stdc++.h>
using namespace std;

int x[100001];
int ans[100001];
int indices[1000001];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        indices[x[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        int idx = indices[x[i]];
        for (int j = 1; j * j <= x[i]; j++) {
            if (x[i] % j == 0) {
                int jdx = indices[j];
                if (jdx > 0) {
                    ans[idx]--;
                    ans[jdx]++;
                }
                if (x[i] == j * j) continue;
                jdx = indices[x[i] / j];
                if (jdx > 0) {
                    ans[idx]--;
                    ans[jdx]++;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}