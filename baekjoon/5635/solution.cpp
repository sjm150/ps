#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<tuple<int, int, int, string>> ymds(n);
    for (auto &[y, m, d, s]: ymds) cin >> s >> d >> m >> y;
    sort(ymds.begin(), ymds.end());
    cout << get<3>(*prev(ymds.end())) << '\n';
    cout << get<3>(*ymds.begin()) << '\n';
}