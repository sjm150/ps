#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int k; cin >> k;
    cout << setprecision(2) << fixed << min(max(100., 25 + k * .01), 2000.) << '\n';
}