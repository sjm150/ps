#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        while (n--) {
            int x; cin >> x;
            pq.push(x);
        }
        ll sum = 0;
        while (pq.size() > 1) {
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            sum += a + b;
            pq.push(a + b);
        }
        cout << sum << '\n';
    }
}