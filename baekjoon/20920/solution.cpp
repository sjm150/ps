#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> psi;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    map<string, int> cnt;
    while (n--) {
        string s; cin >> s;
        if (s.size() >= m) cnt[s]++;
    }

    vector<psi> ord;
    for (auto &[s, cnt]: cnt) ord.emplace_back(s, cnt);
    sort (ord.begin(), ord.end(), [](psi &a, psi &b){
        if (a.second == b.second) {
            if (a.first.size() == b.first.size()) return a < b;
            return a.first.size() > b.first.size();
        }
        return a.second > b.second;
    });

    for (auto &[s, cnt]: ord) cout << s << '\n';
}