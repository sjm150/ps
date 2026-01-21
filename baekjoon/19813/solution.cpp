#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int d, m, y;
        if (s.find('.') < s.size()) {
            auto p = find(s.begin(), s.end(), '.');
            d = stoi(string(s.begin(), p));
            auto q = find(p + 1, s.end(), '.');
            m = stoi(string(p + 1, q));
            y = stoi(string(q + 1, s.end()));
        } else {
            auto p = find(s.begin(), s.end(), '/');
            m = stoi(string(s.begin(), p));
            auto q = find(p + 1, s.end(), '/');
            d = stoi(string(p + 1, q));
            y = stoi(string(q + 1, s.end()));
        }
        cout << right << setfill('0') << setw(2) << d << '.' << setw(2) << m << '.' << setw(4) << y << ' ';
        cout << right << setfill('0') << setw(2) << m << '/' << setw(2) << d << '/' << setw(4) << y << '\n';
    }
}