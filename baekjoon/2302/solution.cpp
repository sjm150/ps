#include <iostream>
using namespace std;

bool fix[40];
int cnt[40];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int idx; cin >> idx;
        fix[idx - 1] = true;
    }
    cnt[0] = cnt[1] = 1;
    if (!fix[0] && !fix[1]) cnt[1]++;
    for (int i = 2; i < n; i++) {
        cnt[i] = cnt[i - 1];
        if (!fix[i - 1] && !fix[i]) cnt[i] += cnt[i - 2];
    }
    cout << cnt[n - 1] << '\n';
}