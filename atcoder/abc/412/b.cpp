#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s, t;
    cin >> s >> t;
    vector<bool> exst(52, false);
    auto idx = [](char c) {
        if (c >= 'a') return c - 'a' + 26;
        else return c - 'A';
    };
    for (char c: t) exst[idx(c)] = true;
    bool ok = true;
    for (int i = 1; i < int(s.size()); i++) {
        if (s[i] < 'a' && !exst[idx(s[i - 1])]) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
}