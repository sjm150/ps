#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int, int>> ord(n);
    for (int i = 0; i < n; i++) {
        cin >> ord[i].first;
        ord[i].second = i;
    }
    sort(ord.begin(), ord.end());

    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, ord[i].second - i);
    cout << ans + 1 << '\n';
}