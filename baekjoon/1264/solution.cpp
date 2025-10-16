#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const string v = "aeiouAEIOU";
    for (;;) {
        string s;
        getline(cin, s);
        if (s == "#") break;
        int ans = 0;
        for (char c: s) ans += find(v.begin(), v.end(), c) != v.end();
        cout << ans << '\n';
    }
}