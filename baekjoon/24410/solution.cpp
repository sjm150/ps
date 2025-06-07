#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> x(n);
    for (int &x: x) cin >> x;

    vector<string> ans(n);
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        function<void(int)> make = [&](int x) {
            if (x == 1) {
                ans[i] += '1';
                return;
            }
            make(x / 2);
            ans[i] += "d+";
            cnt++;
            if (x % 2) {
                ans[i] += "1+";
                cnt++;
            }
        };
        make(x[i] + cnt);
    }

    for (auto &s: ans) cout << s;
    cout << '\n';
}