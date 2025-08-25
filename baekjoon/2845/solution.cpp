#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int l, p, a[5];
    cin >> l >> p;
    for (int &a: a) {
        cin >> a;
        cout << a - l * p << ' ';
    }
    cout << '\n';
}