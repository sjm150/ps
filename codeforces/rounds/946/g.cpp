#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int m, x; cin >> m >> x;
        vector<int> c(m);
        for (int &c: c) cin >> c;

        priority_queue<int> pq;
        int cur = 0;
        for (int c: c) {
            if (cur >= c) {
                cur -= c;
                pq.push(c);
            } else if (!pq.empty() && pq.top() > c) {
                cur += pq.top() - c;
                pq.pop();
                pq.push(c);
            }
            cur += x;
        }

        cout << pq.size() << '\n';
    }
}