#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int v; cin >> v;
    int cnt = 0;
    while (v--) {
        char c; cin >> c;
        if (c == 'A') cnt++;
        else cnt--;
    }
    if (cnt > 0) cout << "A\n";
    else if (cnt < 0) cout << "B\n";
    else cout << "Tie\n";
}