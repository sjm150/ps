#include <bits/stdc++.h>
using namespace std;

unordered_set<string> words;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    char pre = ' ', nxt = ' ';
    int qst = 0;
    while (n--) {
        string s; cin >> s;
        if (s == "?") {
            qst++;
        } else {
            words.insert(s);
            if (qst == 0) pre = s[s.length() - 1];
            if (qst == 1) {
                nxt = s[0];
                qst++;
            }
        }
    }
    int m; cin >> m;
    while (m--) {
        string s; cin >> s;
        if (words.find(s) == words.end() &&
            (pre == ' ' || s[0] == pre) && (nxt == ' ' || s[s.length() - 1] == nxt)) {
            cout << s << '\n';
        }
    }
}