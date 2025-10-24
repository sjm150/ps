#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    auto cnt = [&](string &s) {
        int ret = s[0] != s[n - 1];
        for (int i = 1; i < n; i++) {
            if (s[i - 1] != s[i]) ret++;
        }
        return ret;
    };
    int sc = cnt(s), tc = cnt(t);
    cout << (sc >= tc && sc > 0 && tc < n ? "yes\n" : "no\n");
}