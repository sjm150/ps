#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        auto get = [&](int i) { return s[i] - 'A'; };
        cout << (abs(get(0) * 26 * 26 + get(1) * 26 + get(2) - stoi(s.substr(4, 4))) <= 100 ? "nice\n" : "not nice\n");
    }
}