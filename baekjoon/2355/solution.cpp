#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    long long a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    cout << (a + b) * (b - a + 1) / 2 << '\n';
}