#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        int con = 0, vow = 0;
        for (char c: s) {
            const string v = "AEIOUaeiou";
            if (v.find(c) < 10) vow++;
            else if (c != ' ') con++;
        }
        cout << con << ' ' << vow << '\n';
    }
}