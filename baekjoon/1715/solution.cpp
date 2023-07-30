#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (n--) {
        int num; cin >> num;
        pq.push(num);
    }
    int sum = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        sum += a + b;
        pq.push(a + b);
    }
    cout << sum << '\n';
}