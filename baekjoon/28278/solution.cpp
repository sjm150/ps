#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    stack<int> stk;
    while (n--) {
        int c; cin >> c;
        if (c == 1) {
            int x; cin >> x;
            stk.push(x);
        } else if (c == 2) {
            if (stk.empty()) {
                cout << -1 << '\n';
            } else {
                cout << stk.top() << '\n';
                stk.pop();
            }
        } else if (c == 3) {
            cout << stk.size() << '\n';
        } else if (c == 4) {
            cout << stk.empty() << '\n';
        } else {
            if (stk.empty()) cout << -1 << '\n';
            else cout << stk.top() << '\n';
        }
    }
}