#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int, int>> ai(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        ai[i] = {a, i};
    }
    sort(ai.begin(), ai.end());
    vector<int> p(n);
    for (int i = 0; i < n; i++) p[ai[i].second] = i;
    for (int p: p) cout << p << ' ';
    cout << '\n';
}