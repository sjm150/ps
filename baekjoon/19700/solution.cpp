#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

pair<int, int> studs[500000];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int h, k; cin >> h >> k;
        studs[i] = {h, k};
    }
    sort(studs, studs + n, greater<pair<int, int>>());
    multiset<int> teams;
    for (int i = 0; i < n; i++) {
        auto [h, k] = studs[i];
        auto it = teams.upper_bound(k - 1);
        if (it == teams.begin()) {
            teams.insert(1);
        } else {
            it--;
            int v = *it;
            teams.erase(it);
            teams.insert(v + 1);
        }
    }
    cout << teams.size() << '\n';
}