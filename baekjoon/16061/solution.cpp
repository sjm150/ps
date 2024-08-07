#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, d, k; cin >> n >> d >> k;
    vector<pair<string, int>> sc(n);
    for (auto &[s, c]: sc) cin >> s >> c;
    sort(sc.begin(), sc.end(), [](auto &a, auto &b) { return a.second > b.second; });
    int sum = 0;
    for (int i = 0; i < k; i++) sum += sc[i].second;
    if (sum >= d) {
        cout << k << '\n';
        for (int i = 0; i < k; i++) cout << sc[i].first << ", YOU ARE FIRED!\n";
    } else {
        cout << "impossible\n";
    }
}