#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, c; cin >> n >> c;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    vector<int> sums;
    for (int i = 0; i < (1 << (n / 2)); i++) {
        int sum = 0, bm = i, idx = 0;
        while (bm) {
            if (bm % 2) sum += w[idx];
            if (sum > inf) break;
            bm /= 2;
            idx++;
        }
        if (sum <= inf) sums.push_back(sum);
    }
    sort(sums.begin(), sums.end());

    int cnt = 0;
    for (int i = 0; i < (1 << (n - n / 2)); i++) {
        int sum = 0, bm = i, idx = n / 2;
        while (bm) {
            if (bm % 2) sum += w[idx];
            if (sum > inf) break;
            bm /= 2;
            idx++;
        }
        cnt += upper_bound(sums.begin(), sums.end(), c - sum) - sums.begin();
    }

    cout << cnt << '\n';
}