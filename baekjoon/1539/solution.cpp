#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

set<int> bt;
int h[250000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int x; cin >> x;
    bt.insert(x);
    h[x] = 1;
    for (int i = 1; i < n; i++) {
        cin >> x;
        auto it = bt.upper_bound(x);
        if (it == bt.begin()) h[x] = h[*it] + 1;
        else if (it == bt.end()) h[x] = h[*prev(it)] + 1;
        else h[x] = max(h[*prev(it)], h[*it]) + 1;
        bt.insert(x);
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) sum += h[i];
    cout << sum << '\n';
}