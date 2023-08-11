#include <iostream>
#include <vector>
using namespace std;

vector<int> getpi(string& s) {
    vector<int> pi(s.size() + 1);
    int i = 1, j = 0;
    pi[0] = -1;
    while (i < s.size()) {
        if (s[i] == s[j]) {
            pi[i] = pi[j];
        } else {
            pi[i] = j;
            while (j >= 0 && s[i] != s[j]) j = pi[j];
        }
        i++, j++;
    }
    pi[i] = j;
    return pi;
}

int idx[256];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    while (n--) {
        string a, w, s; cin >> a >> w >> s;
        auto pi = getpi(w);
        vector<int> ans;
        for (int i = 0; i < a.size(); i++) idx[a[i]] = i;
        for (int v = 0; v < a.size(); v++) {
            int cnt = 0;
            int i = 0, j = 0;
            while (i < s.size()) {
                int c = idx[w[j]] + v;
                if (c >= a.size()) c -= a.size();
                if (j < 0 || idx[s[i]] == c) {
                    i++, j++;
                    if (j == w.size()) {
                        cnt++;
                        if (cnt > 1) break;
                        else j = pi[j];
                    }
                } else {
                    j = pi[j];
                }
            }
            if (cnt == 1) ans.push_back(v);
        }
        if (ans.empty()) {
            cout << "no solution\n";
        } else if (ans.size() == 1) {
            cout << "unique: " << ans[0] << '\n';
        } else {
            cout << "ambiguous:";
            for (int v: ans) cout << ' ' << v;
            cout << '\n';
        }
    }
}