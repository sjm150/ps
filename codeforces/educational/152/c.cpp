#include <iostream>
#include <set>
using namespace std;
 
int conv[200000];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string str; cin >> str;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (str[i] == '1') conv[i] = prev;
            else prev = i;
        }
        prev = n;
        for (int i = n - 1; i >= 0; i--) {
            if (str[i] == '0') conv[i] = prev;
            else prev = i;
        }
        set<pair<int, int>> pset;
        while (m--) {
            int s, e; cin >> s >> e;
            s--, e--;
            if (str[s] == '0') s = conv[s];
            if (str[e] == '1') e = conv[e];
            if (s < e) pset.emplace(s, e);
            else pset.emplace(-1, -1);
        }
        cout << pset.size() << '\n';
    }
}