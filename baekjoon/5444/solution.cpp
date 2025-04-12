#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> sum(m, -1e9);
        sum[0] = 0;
        while (n--) {
            int s; cin >> s;
            auto ns = sum;
            for (int i = 0; i < m; i++) ns[(i + s) % m] = max(ns[(i + s) % m], sum[i] + 1);
            swap(ns, sum);
        }
        cout << sum[0] << '\n';
    }
}