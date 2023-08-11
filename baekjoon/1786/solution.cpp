#include <iostream>
#include <vector>
#include <string>
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

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string t, p; getline(cin, t); getline(cin, p);
    auto pi = getpi(p);
    vector<int> ans;
    int i = 0, j = 0;
    while (i < t.size()) {
        if (j < 0 || t[i] == p[j]) {
            i++, j++;
            if (j == p.size()) {
                ans.push_back(i - j + 1);
                j = pi[j];
            }
        } else {
            j = pi[j];
        }
    }
    cout << ans.size() << '\n';
    for (int i: ans) cout << i << '\n';
}