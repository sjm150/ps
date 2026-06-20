#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    char x;
    cin >> n >> x;
    vector<string> s(n);
    for (auto &s: s) cin >> s;
    bool ok = false;
    for (auto &s: s) {
        if (s[x - 'A'] == 'o') {
            ok = true;
            break;
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
}