#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    priority_queue<pair<int, int>> pq;
    int maxd = 0;
    while (n--) {
        int d, k; cin >> d >> k;
        pq.emplace(k, d);
        maxd = max(maxd, d);
    }
    set<int> days;
    for (int d = 1; d <= maxd; d++) days.insert(d);
    int sum = 0;
    while (!days.empty()) {
        auto it = days.upper_bound(pq.top().second);
        while (it == days.begin()) {
            pq.pop();
            if (pq.empty()) break;
            else it = days.upper_bound(pq.top().second);
        }
        if (pq.empty()) break;
        days.erase(prev(it));
        sum += pq.top().first;
        pq.pop();
    }
    cout << sum << '\n';
}