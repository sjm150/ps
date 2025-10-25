#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int x = 0, y = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a > b) x++;
        else if (a < b) y++;
    }
    cout << x << ' ' << y << '\n';
}