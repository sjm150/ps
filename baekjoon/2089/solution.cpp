#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    stack<int> stk;
    while (n) {
        if (n % -2) {
            n -= 1;
            stk.push(1);
        } else {
            stk.push(0);
        }
        n /= -2;
    }
    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
    cout << '\n';
}