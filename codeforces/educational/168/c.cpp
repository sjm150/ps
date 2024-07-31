#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int o = 0, c = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                o++;
            } else if (s[i] == ')') {
                c++;
            } else {
                b++;
            }
        }

        stack<int> stk;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                ans += i - stk.top();
                stk.pop();
            } else {
                if (stk.empty()) {
                    stk.push(i);
                    o++;
                } else if (b + o == c) {
                    stk.push(i);
                    o++;
                } else {
                    ans += i - stk.top();
                    stk.pop();
                    c++;
                }
                b--;
            }
        }
        cout << ans << '\n';
    }
}