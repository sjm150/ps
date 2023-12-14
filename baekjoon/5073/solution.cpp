#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int l[3];
    while (true) {
        cin >> l[0] >> l[1] >> l[2];
        if (l[0] == 0) break;
        sort(l, l + 3);
        if (l[2] >= l[0] + l[1]) cout << "Invalid\n";
        else if (l[0] == l[1] && l[1] == l[2]) cout << "Equilateral\n";
        else if (l[0] == l[1] || l[1] == l[2] || l[2] == l[0]) cout << "Isosceles\n";
        else cout << "Scalene\n";
    }
}