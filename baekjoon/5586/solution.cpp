#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.size() - 2; i++) {
        string ss = s.substr(i, 3);
        if (ss == "JOI") a++;
        else if (ss == "IOI") b++;
    }
    cout << a << '\n' << b << '\n';
}