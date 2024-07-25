#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    string s;
    for (int i = 0; i < n; i++) s += '@';
    for (int i = 0; i < 4 * n; i++) cout << s << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) cout << s;
        cout << '\n';
    }
}