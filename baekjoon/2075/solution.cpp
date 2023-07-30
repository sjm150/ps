#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int nn = n * n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (nn--) {
        int x; cin >> x;
        pq.push(x);
        if (pq.size() > n) pq.pop();
    }
    cout << pq.top() << '\n';
}