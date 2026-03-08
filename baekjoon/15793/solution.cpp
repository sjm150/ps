#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int sz = 26;
    string a, b;
    cin >> a >> b;
    
    vector<int> ac(sz, 0), bc(sz, 0);
    for (char c: a) ac[c - 'A']++;
    for (char c: b) bc[c - 'A']++;

    vector<int> pref(sz);
    pref[0] = ac[0] - bc[0];
    for (int i = 1; i < sz; i++) pref[i] = pref[i - 1] + ac[i] - bc[i];

    int st = (min_element(pref.begin(), pref.end()) - pref.begin() + 1) % sz, cnt = 0, ans = 0;
    for (int i = 0; i < sz; i++) {
        ans += cnt;
        int idx = (st + i) % 26;
        cnt += ac[idx] - bc[idx];
    }
    cout << ans << '\n';
}