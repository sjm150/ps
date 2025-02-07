#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    for (int i = 0; i < 9; i++) {
        int x; cin >> x;
        t -= x;
    }
    cout << t << '\n';
}