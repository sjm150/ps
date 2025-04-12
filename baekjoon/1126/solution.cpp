#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int sz = 500001, bs = sz / 2;
    int n; cin >> n;
    vector<int> sum(sz, -1);
    sum[bs] = 0;
    while (n--) {
        int h; cin >> h;
        auto ns = sum;
        for (int i = 0; i < sz; i++) {
            if (sum[i] < 0) continue;
            if (i - h >= 0) ns[i - h] = max(ns[i - h], sum[i] + h);
            if (i + h < sz) ns[i + h] = max(ns[i + h], sum[i] + h);
        }
        swap(ns, sum);
    }
    cout << (sum[bs] > 0 ? sum[bs] / 2 : -1) << '\n';
}