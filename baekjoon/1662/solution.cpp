#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    int ans = 0;
    stack<int> stk;
    stk.push(1);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            ans -= stk.top();
            stk.push(stk.top() * (s[i - 1] - '0'));
        } else if (s[i] == ')') {
            stk.pop();
        } else {
            ans += stk.top();
        }
    }
    cout << ans << '\n';
}