#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int a = 100, b = 100;
    while (n--) {
        int x, y; cin >> x >> y;
        if (x > y) b -= x;
        else if (x < y) a -= y;
    }
    cout << a << '\n';
    cout << b << '\n';
}