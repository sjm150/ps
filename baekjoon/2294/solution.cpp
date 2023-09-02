#include <iostream>
using namespace std;
const int inf = 123456789;

int vs[100];
int mcnt[100001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> vs[i];
    fill(mcnt, mcnt + k + 1, inf);
    mcnt[0] = 0;
    for (int v: vs) {
        for (int i = v; i <= k; i++) mcnt[i] = min(mcnt[i], mcnt[i - v] + 1);
    }
    if (mcnt[k] < inf) cout << mcnt[k] << '\n';
    else cout << -1 << '\n';
}