#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll k; cin >> k;
    string s; cin >> s;

    int len = 0;
    for (ll i = k; i; i >>= 1) len++;

    if (len > s.size()) {
        cout << 0 << '\n';
        return 0;
    }

    string ss = "1";
    for (int i = 1; i < s.size(); i++) {
        if (ss.size() + s.size() - i > len && s[i] == '1') continue;
        ss += s[i];
    }
    while (ss.size() > len) ss.pop_back();

    ll v = 0;
    for (char c: ss) v = v * 2 + c - '0';
    cout << s.size() - len + (v > k) << '\n';
}