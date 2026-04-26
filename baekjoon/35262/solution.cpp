#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int mx = 0, len = 0;
    for (char c: s) {
        if (c == '0') {
            len++;
            mx = max(mx, len);
        } else {
            len = 0;
        }
    }
    cout << (mx < k) << '\n';
}