#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string l, s;
        getline(cin, l);
        stringstream ss(l);
        while (ss >> s) {
            reverse(s.begin(), s.end());
            cout << s << ' ';
        }
        cout << '\n';
    }
}