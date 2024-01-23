#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];

    int i = 0, sum = 0;
    while (i < k) sum += t[i++];

    int maxs = sum;
    for (; i < n; i++) {
        sum += t[i] - t[i - k];
        maxs = max(maxs, sum);
    }
    cout << maxs << '\n';
}