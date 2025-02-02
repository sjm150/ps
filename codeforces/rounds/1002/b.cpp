#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int sz = n - k + 1;
        k /= 2;
        int idx = 0, ans = k + 1;
        queue<int> q;
        multiset<int> ms;
        for (int i = 1; i <= k; i++) {
            idx++;
            while (ms.size() < sz) {
                q.push(idx);
                ms.insert(a[idx++]);
            }
            if (*ms.begin() < i || i < *prev(ms.end())) {
                ans = i;
                break;
            }
            ms.erase(ms.find(a[q.front()]));
            q.pop();
        }
        cout << ans << '\n';
    }
}