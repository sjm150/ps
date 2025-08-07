#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        priority_queue<int> pq;
        for (int a: a) pq.push(a);
        int ans = 0;
        long long coef = 1;
        while (!pq.empty()) {
            if (pq.top() * coef > c) {
                ans++;
            } else {
                coef *= 2;
            }
            pq.pop();
        }

        cout << ans << '\n';
    }
}