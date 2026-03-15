#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        int cnt = count(s.begin(), s.end(), 'g') + count(s.begin(), s.end(), 'G') - count(s.begin(), s.end(), 'b') - count(s.begin(), s.end(), 'B');
        cout << s << " is " << (cnt > 0 ? "GOOD\n" : cnt < 0 ? "A BADDY\n" : "NEUTRAL\n");
    }
}