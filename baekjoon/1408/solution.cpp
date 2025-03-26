#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s, e; cin >> s >> e;
    auto t = [&](string &s) {
        return stoi(s.substr(0, 2)) * 3600 + stoi(s.substr(3, 2)) * 60 + stoi(s.substr(6, 2));
    };
    int d = (t(e) - t(s) + 86400) % 86400;
    cout << setw(2) << setfill('0') << d / 3600 << ':' << setw(2) << setfill('0') << d / 60 % 60 << ':' << setw(2) << setfill('0') << d % 60 << '\n';
}