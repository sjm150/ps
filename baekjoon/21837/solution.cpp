#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<string> name(n);
    map<string, int> idx;
    auto geti = [&](string &s) {
        auto it = idx.find(s);
        if (it == idx.end()) {
            int i = idx.size();
            name[i] = s;
            idx.emplace(s, i);
            return i;
        }
        return it->second;
    };

    vector<vector<int>> edges(n);
    string line;
    getline(cin, line);
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss;
        ss << line;
        string s; ss >> s;
        int d = geti(s);
        for (int j = 0; j < 3; j++) ss >> s;
        while (ss >> s) edges[geti(s)].push_back(d);
    }

    vector<int> dst(n, 0);
    queue<int> q;
    dst[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt: edges[cur]) {
            if (dst[nxt] == 0) {
                dst[nxt] = dst[cur] + 1;
                q.push(nxt);
            }
        }
    }

    vector<pair<string, int>> ans(n);
    for (int i = 0; i < n; i++) ans[i] = make_pair(name[i], dst[i]);
    sort(ans.begin(), ans.end());
    for (auto &[s, d]: ans) cout << d << '\n';
}