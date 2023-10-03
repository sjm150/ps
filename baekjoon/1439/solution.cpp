#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    int scnt[2] = {0, 0};
    scnt[s[0] - '0']++;
    for (int i = 1; i < s.length(); i++) {
        if (s[i - 1] != s[i]) scnt[s[i] - '0']++;
    }
    cout << min(scnt[0], scnt[1]) << '\n';
}