#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    if (a < 2) cout << "Before\n";
    else if (a > 2) cout << "After\n";
    else if (b < 18) cout << "Before\n";
    else if (b > 18) cout << "After\n";
    else cout << "Special\n";
}