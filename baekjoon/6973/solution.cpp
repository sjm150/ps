#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<string>> txt;
        for (;;) {
            string s;
            getline(cin, s);
            if (s.empty()) break;
            stringstream ss(s);
            txt.emplace_back();
            while (ss >> s) txt.back().push_back(s);
        }
        map<string, int> idx;
        for (auto &s: txt) {
            for (auto &s: s) {
                auto it = idx.find(s);
                if (it == idx.end()) {
                    idx[s] = idx.size() + 1;
                    cout << s << ' ';
                } else {
                    cout << it->second << ' ';
                }
            }
            cout << '\n';
        }
        cout << '\n';
    }
}