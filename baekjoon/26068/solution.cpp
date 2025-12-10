#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        string s;
        cin >> s;
        ans += stoi(s.substr(2)) <= 90;
    }
    cout << ans << '\n';
}