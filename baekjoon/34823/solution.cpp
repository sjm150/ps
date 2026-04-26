#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int y, c, p;
    cin >> y >> c >> p;
    cout << min(y, min(c / 2, p)) << '\n';
}