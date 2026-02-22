#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    map<string, int> cnt;
    while (n--) {
        string s;
        cin >> s;
        cnt[s]++;
    }
    int mx = 0;
    for (auto &[_, c]: cnt) mx = max(mx, c);
    for (auto &[s, c]: cnt) {
        if (c == mx) {
            cout << s << '\n';
            break;
        }
    }
}