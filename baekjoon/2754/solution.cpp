#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    map<string, float> v = {
        make_pair("A+", 4.3),
        make_pair("A0", 4.0),
        make_pair("A-", 3.7),
        make_pair("B+", 3.3),
        make_pair("B0", 3.0),
        make_pair("B-", 2.7),
        make_pair("C+", 2.3),
        make_pair("C0", 2.0),
        make_pair("C-", 1.7),
        make_pair("D+", 1.3),
        make_pair("D0", 1.0),
        make_pair("D-", 0.7),
        make_pair("F", 0.0)
    };
    string s; cin >> s;
    cout << fixed << setprecision(1) << v[s] << '\n';
}