#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool used[26] = {};
    for (char c: s) used[c - 'A'] = true;
    int cur = 0, lst = s[n - 1] - 'A';
    for (int i = 0; i < n - 1; i++) cur += s[i] < s[i + 1] ? 1 : -1;

    if (cur > 1) {
        while (cur > 1) {
            while (used[lst]) {
                lst--;
                if (lst == -1) lst = 25;
            }
            char c = 'A' + lst;
            cur += s.back() < c ? 1 : -1;
            s.push_back(c);
            used[lst] = true;
        }
    } else if (cur < -1) {
        while (cur < -1) {
            while (used[lst]) {
                lst++;
                if (lst == 26) lst = 0;
            }
            char c = 'A' + lst;
            cur += s.back() < c ? 1 : -1;
            s.push_back(c);
            used[lst] = true;
        }
    }

    cout << s.size() << '\n';
    cout << s << '\n';
}