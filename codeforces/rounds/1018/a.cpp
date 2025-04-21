#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> ans(n);
        int l = 1, r = n;
        for (int i = n - 1; i; i--) {
            if (s[i - 1] == '<') ans[i] = l++;
            else ans[i] = r--;
        }
        ans[0] = l;
        for (int a: ans) cout << a << ' ';
        cout << '\n';
    }
}