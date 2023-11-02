#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        deque<int> dq;
        for (int ai: a) dq.push_back(ai);

        ll moves = 0;
        while (!dq.empty()) {
            int x = 0;
            while (x < dq.back()) {
                if (dq.size() == 1) {
                    int t = x + dq.back();
                    if (t == 1) x = 0;
                    else x = t / 2 + (t & 1);
                    break;
                }
                x += dq.front(); dq.pop_front();
                if (x > dq.back()) {
                    dq.push_front(x - dq.back());
                    x = dq.back();
                }
            }
            moves += x + 1;
            dq.pop_back();
        }

        cout << moves << '\n';
    }
}