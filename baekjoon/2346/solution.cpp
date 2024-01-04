#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    deque<pair<int, int>> dq;
    for (int i = 1; i <= n; i++) {
        int c; cin >> c;
        dq.emplace_back(i, c);
    }

    while (!dq.empty()) {
        auto [i, c] = dq.front(); dq.pop_front();
        cout << i << ' ';
        if (c > 0) {
            c--;
            while (c--) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            c = -c;
            while (c--) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    cout << '\n';
}