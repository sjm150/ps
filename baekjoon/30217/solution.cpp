#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s, t; cin >> s >> t;
    auto vwl = [](char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };

    int i = 1;
    while (i < s.size() && !vwl(s[i])) i++;
    int j = t.size() - 2;
    while (j >= 0 && !vwl(t[j])) j--;

    if (j >= 0) {
        for (int k = 0; k < i; k++) cout << s[k];
        for (int k = j; k < t.size(); k++) cout << t[k];
        cout << '\n';
    } else {
        for (int k = 0; k < i; k++) cout << s[k];
        cout << (i < s.size() ? s[i] : 'o');
        for (int k = j + 1; k < t.size(); k++) cout << t[k];
        cout << '\n';
    }
}