#include <iostream>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;

pair<int, int> jewels[300000];
map<int, int> bag;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int m, v; cin >> m >> v;
        jewels[i] = {v, m};
    }
    sort(jewels, jewels + n);
    while (k--) {
        int c; cin >> c;
        if (bag.find(c) == bag.end()) bag[c] = 1;
        else bag[c]++;
    }
    ll sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (bag.size() == 0) break;
        auto it = bag.lower_bound(jewels[i].second);
        if (it == bag.end()) continue;
        sum += jewels[i].first;
        it->second--;
        if (it->second == 0) bag.erase(it);
    }
    cout << sum << '\n';
}