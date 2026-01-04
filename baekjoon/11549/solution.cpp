#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t, a[5];
    cin >> t;
    for (int &a: a) cin >> a;
    cout << count(a, a + 5, t) << '\n';
}