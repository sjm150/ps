#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    deque<int> dq;
    while (n--) {
        int c, x; cin >> c;
        if (c == 1) {
            cin >> x;
            dq.push_front(x);
        } else if (c == 2) {
            cin >> x;
            dq.push_back(x);
        } else if (c == 3) {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } else if (c == 4) {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        } else if (c == 5) {
            cout << dq.size() << '\n';
        } else if (c == 6) {
            cout << dq.empty() << '\n';
        } else if (c == 7) {
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        } else {
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }
}