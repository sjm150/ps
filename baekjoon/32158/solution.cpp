#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p, c;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') p.push_back(i);
        else if (s[i] == 'C') c.push_back(i);
    }
    for (int i = 0; i < int(min(p.size(), c.size())); i++) swap(s[p[i]], s[c[i]]);
    cout << s << '\n';
}