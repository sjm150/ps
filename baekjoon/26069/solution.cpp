#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    map<string, int> idx;
    vector<bool> chk;
    idx["ChongChong"] = 0;
    chk.push_back(true);

    int n; cin >> n;
    while (n--) {
        string a, b; cin >> a >> b;
        if (idx.find(a) == idx.end()) {
            idx[a] = idx.size();
            chk.push_back(false);
        }
        if (idx.find(b) == idx.end()) {
            idx[b] = idx.size();
            chk.push_back(false);
        }
        int ai = idx[a], bi = idx[b];
        if (chk[ai] || chk[bi]) chk[ai] = chk[bi] = true;
    }

    int cnt = 0;
    for (int i = 0; i < chk.size(); i++) {
        if (chk[i]) cnt++;
    }
    cout << cnt << '\n';
}