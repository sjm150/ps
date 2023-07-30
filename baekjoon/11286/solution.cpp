#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pi;

priority_queue<pi, vector<pi>, greater<pi>> pq;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        if (x == 0) {
            if (!pq.empty()) {
                cout << pq.top().second << '\n';
                pq.pop();
            } else {
                cout << 0 << '\n';
            }
        } else {
            pq.emplace(abs(x), x);
        }
    }
}