#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    long long s; cin >> s;
    int x = 1;
    for (; x <= s; x++) s -= x;
    cout << x - 1 << '\n';
}