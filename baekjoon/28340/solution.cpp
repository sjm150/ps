#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        priority_queue<int, vector<int>, greater<int>> pq;
        while (n--) {
            int c;
            cin >> c;
            pq.push(c);
        }
        while ((pq.size() - 1) % (k - 1)) pq.push(0);
        long long ans = 0;
        while (pq.size() > k) {
            int sum = 0;
            for (int i = 0; i < k; i++) {
                sum += pq.top();
                pq.pop();
            }
            ans += sum;
            pq.push(sum);
        }
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        cout << ans << '\n';
    }
}