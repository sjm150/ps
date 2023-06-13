#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, l;
    cin >> n >> l;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.emplace(num, i);
        while (pq.top().second <= i - l) pq.pop();
        cout << pq.top().first << ' ';
    }
    cout << '\n';
}