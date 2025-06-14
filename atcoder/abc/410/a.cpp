#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    int k;
    cin >> k;
    sort(a.begin(), a.end());
    cout << a.end() - lower_bound(a.begin(), a.end(), k) << '\n';
}