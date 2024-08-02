#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    int j; cin >> j;
    int l = 0, r = j + *max_element(a.begin(), a.end()) + 1;
    while (l < r) {
        int m = (l + r) / 2;
        long long cnt = 0;
        for (int a: a) {
            if (a < m) cnt += m - a;
        }
        if (cnt > j || cnt > m) r = m;
        else l = m + 1;
    }
    cout << r - 1 << '\n';
}