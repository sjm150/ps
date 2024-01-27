#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    set<string> chk;
    int cnt = 0;
    while (n--) {
        string s; cin >> s;
        if (s == "ENTER") {
            chk = set<string>();
        } else if (chk.find(s) == chk.end()) {
            cnt++;
            chk.insert(s);
        }
    }
    cout << cnt << '\n';
}