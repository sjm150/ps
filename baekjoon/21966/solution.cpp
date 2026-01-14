#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n <= 25) {
        cout << s << '\n';
    } else if (find(s.begin() + 11, s.end(), '.') >= s.end() - 12) {
        cout << s.substr(0, 11) << "..." << s.substr(n - 11) << '\n';
    } else {
        cout << s.substr(0, 9) << "......" << s.substr(n - 10) << '\n';
    }
}