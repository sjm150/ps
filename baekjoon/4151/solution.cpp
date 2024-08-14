#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<string> ss;
    string s;
    while (cin >> s) ss.push_back(s);
    set<string> occ;
    for (string &s: ss) occ.emplace(s);
    for (string &s: ss) {
        bool poss = false;
        for (int i = 1; i < s.size(); i++) {
            if (occ.find(s.substr(0, i)) != occ.end() && occ.find(s.substr(i)) != occ.end()) {
                poss = true;
                break;
            }
        }
        if (poss) cout << s << '\n';
    }
}