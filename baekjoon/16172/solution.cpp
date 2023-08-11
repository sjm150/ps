#include <iostream>
#include <vector>
using namespace std;

vector<int> getpi(string& s) {
    vector<int> pi(s.size());
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
    return pi;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s, k; cin >> s >> k;
    auto pi = getpi(k);
    bool find = false;
    int i = 0, j = 0;
    while (i < s.size()) {
        if ('0' <= s[i] && s[i] <= '9') {
            i++;
            continue;
        }
        if (j == -1 || s[i] == k[j]) {
            i++, j++;
            if (j == k.size()) {
                find = true;
                break;
            }
        } else {
            j = pi[j];
        }
    }
    cout << (find ? 1 : 0) << '\n';
}