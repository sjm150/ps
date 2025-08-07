#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int &p: p) cin >> p;

        string ans;
        int l = 0, r = n - 1, pre = 0, pp = -1;
        while (l <= r) {
            bool usel = true;
            if (pre < p[l] && pre < p[r]) {
                if (p[l] < p[r]) usel = false;
            } else if (pre > p[l] && pre > p[r]) {
                if (p[l] > p[r]) usel = false;
            } else if (pp < pre) {
                if (p[l] > p[r]) usel = false;
            } else {
                if (p[l] < p[r]) usel = false;
            }
            pp = pre;
            if (usel) {
                ans += 'L';
                pre = p[l++];;
            } else {
                ans += 'R';
                pre = p[r--];
            }
        }

        cout << ans << '\n';
    }
}