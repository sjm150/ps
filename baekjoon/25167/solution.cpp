#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, p; cin >> n >> m >> p;
    vector<string> name(m);
    map<string, int> idx;
    for (int i = 0; i < m; i++) {
        cin >> name[i];
        idx[name[i]] = i;
    }

    vector<vector<int>> lst(n, vector<int>(m, 0)), dur(n, vector<int>(m, inf));
    while (p--) {
        int k, h, m;
        char c;
        string s, r;
        cin >> k >> h >> c >> m >> s >> r;
        k--;
        int t = h * 60 + m, i = idx[s];
        if (lst[k][i] < 0) continue;
        if (r[0] == 's') {
            if (lst[k][i] > 0) dur[k][i] = t - lst[k][i];
            lst[k][i] = -1;
        } else if (lst[k][i] == 0) {
            lst[k][i] = t;
        }
    }

    vector<int> scr(m, 0);
    for (int k = 0; k < n; k++) {
        vector<pair<int, string>> ord(m);
        for (int i = 0; i < m; i++) ord[i] = {dur[k][i], name[i]};
        sort(ord.begin(), ord.end());
        for (int i = 0; i < m; i++) {
            auto &[dur, name] = ord[i];
            int &s = scr[idx[name]];
            if (dur < inf) s += i + 1;
            else if (lst[k][idx[name]] > 0) s += m;
            else s += m + 1;
        }
    }

    vector<pair<int, string>> ord(m);
    for (int i = 0; i < m; i++) ord[i] = {scr[i], name[i]};
    sort(ord.begin(), ord.end());
    for (auto &[scr, name]: ord) cout << name << '\n';
}