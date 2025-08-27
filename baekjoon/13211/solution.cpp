#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    set<string> s;
    while (n--) {
        string t;
        cin >> t;
        s.insert(t);
    }
    int m;
    cin >> m;
    int ans = 0;
    while (m--) {
        string t;
        cin >> t;
        if (s.find(t) != s.end()) ans++;
    }
    cout << ans << '\n';
}