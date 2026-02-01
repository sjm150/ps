#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    if (a[1] - a[0] == a[2] - a[1]) cout << a.back() + a[1] - a[0] << '\n';
    else cout << a.back() / a[0] * a[1] << '\n';
}