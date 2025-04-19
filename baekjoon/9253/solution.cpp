#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef struct Kmp {
        string p;
        vector<int> pi;
        Kmp(string &s): p(s) {
            int sz = p.size(), i = 1, j = 0;
            pi.resize(sz + 1);
            pi[0] = -1;
            while (i < sz) {
                if (p[i] == p[j]) {
                    pi[i] = pi[j];
                } else {
                    pi[i] = j;
                    while (j >= 0 && p[i] != p[j]) j = pi[j];
                }
                i++, j++;
            }
            pi[i] = j;
        }
        int find(string &s) {
            int sz = s.size(), i = 0, j = 0;
            while (i < sz) {
                if (j < 0 || s[i] == p[j]) {
                    i++, j++;
                    if (j == p.size()) return i - j + 1;
                } else {
                    j = pi[j];
                }
            }
            return -1;
        }
    } kmp_t;
    string a, b, s; cin >> a >> b >> s;
    kmp_t kmp(s);
    cout << (kmp.find(a) >= 0 && kmp.find(b) >= 0 ? "YES\n" : "NO\n");
}