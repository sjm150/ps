#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n), fre(mx + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fre[a[i]]++;
    }
    vector<int> ans(n);
    stack<int> stk;
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && fre[stk.top()] <= fre[a[i]]) stk.pop();
        if (!stk.empty()) ans[i] = stk.top();
        else ans[i] = -1;
        stk.push(a[i]);
    }
    for (int a: ans) cout << a << ' ';
    cout << '\n';
}