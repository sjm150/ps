#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int x[10];
    for (int &x: x) cin >> x;
    int sum = 0;
    map<int, int> cnt;
    for (int x: x) {
        sum += x;
        cnt[x]++;
    }
    vector<pair<int, int>> ord;
    for (auto [x, cnt]: cnt) ord.emplace_back(cnt, x);
    cout << sum / 10 << '\n';
    cout << max_element(ord.begin(), ord.end())->second << '\n';
}