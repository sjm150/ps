#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> num(n + 1);
    for (int i = 0; i < n; i++) cin >> num[i];

    stack<int> stk;
    int cur = 1, idx = 0;
    while (cur <= n) {
        if (cur == num[idx]) {
            cur++, idx++;
            continue;
        }
        if (!stk.empty() && cur == stk.top()) {
            cur++;
            stk.pop();
            continue;
        }
        if (idx == n) break;
        stk.push(num[idx++]);
    }

    if (cur > n) cout << "Nice\n";
    else cout << "Sad\n";
}