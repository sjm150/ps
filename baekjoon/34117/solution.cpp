#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    ll sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int a: a) {
        sum += a;
        pq.push(a);
        while (!pq.empty() && sum - pq.top() >= p) {
            sum -= pq.top();
            pq.pop();
        }
        cout << (sum >= p ? int(pq.size()) : -1) << ' ';
    }
    cout << '\n';
}