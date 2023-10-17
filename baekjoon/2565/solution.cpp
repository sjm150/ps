#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

pi conn[101];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> conn[i].first >> conn[i].second;
    sort(conn, conn + n);
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        int v = conn[i].second;
        auto it = upper_bound(lis.begin(), lis.end(), v);
        if (it != lis.end()) *it = v;
        else lis.push_back(v);
    }
    cout << n - lis.size() << '\n';
}