#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >>  n;
    vector<int> a(n * 3);
    for (int &a: a) cin >> a;
    sort(a.begin(), a.end());
    cout << a[n * 2 - 1] - a[n] << '\n';
}