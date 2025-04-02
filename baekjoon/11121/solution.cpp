#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string i, o; cin >> i >> o;
        cout << (i == o ? "OK\n" : "ERROR\n");
    }
}