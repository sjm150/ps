#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    for (int a: a) cout << a << ' ';
    cout << '\n';
}