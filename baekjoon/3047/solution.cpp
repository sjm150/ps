#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a[3];
    for (int &a: a) cin >> a;
    string s;
    cin >> s;
    sort(a, a + 3);
    for (char c: s) cout << a[c - 'A'] << ' ';
    cout << '\n';
}