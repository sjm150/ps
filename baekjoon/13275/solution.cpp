#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    string sp = "|";
    for (auto c: s) {
        sp.push_back(c);
        sp.push_back('|');
    }

    int n = sp.size();
    vector<int> len(n);
    int i = 0, r = 0;
    while (i < n) {
        while (i - r - 1 >= 0 && i + r + 1 < n && sp[i - r - 1] == sp[i + r + 1]) r++;
        len[i] = r;

        int pi = i, pr = r;
        for (i++, r = 0; i <= pi + pr; i++) {
            int j = 2 * pi - i;
            int lim = pi + pr - i;
            if (len[j] < lim) len[i] = len[j];
            else if (len[j] > lim) len[i] = lim;
            else {
                r = lim;
                break;
            }
        }
    }

    int ans = 0;
    for (int l: len) ans = max(ans, l);
    cout << ans << '\n';
}