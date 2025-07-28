#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    while (getline(cin, s)) {
        int ans[4] = {};
        for (char c: s) {
            if ('a' <= c && c <= 'z') ans[0]++;
            else if ('A' <= c && c <= 'Z') ans[1]++;
            else if ('0' <= c && c <= '9') ans[2]++;
            else ans[3]++;
        }
        for (int a: ans) cout << a << ' ';
        cout << '\n';
    }
}