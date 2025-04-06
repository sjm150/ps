#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int l, n; cin >> l >> n;
    string s; cin >> s;
    int cnt = 0;
    for (int i = 0; i < l; i++) {
        if (s[i] == 'w') cnt++;
        else if (s[i] == 'h') swap(s[i - min(cnt, n)], s[i]);
        else cnt = 0;
    }
    cout << s << '\n';
}