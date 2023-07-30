#include <iostream>
#include <queue>
using namespace std;

int p[100];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        priority_queue<int> pq;
        queue<int> idx;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            pq.push(p[i]);
            idx.push(i);
        }
        for (int i = 1; !idx.empty(); i++) {
            while (p[idx.front()] != pq.top()) {
                idx.push(idx.front());
                idx.pop();
            }
            if (idx.front() == m) {
                cout << i << '\n';
                break;
            }
            pq.pop();
            idx.pop();
        }
    }
}