#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n; cin >> n;
    string s; cin >> s;
    ll cnt[3] = {};
    for (char c: s) {
        if (c == 'C') cnt[0]++;
        else if (c == 'O') cnt[1] += cnt[0];
        else cnt[2] += cnt[1];
    }
    cout << cnt[2] << '\n';
}