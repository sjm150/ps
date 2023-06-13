#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    deque<int> q;
    for (int i = 1; i <= n; i++) q.push_back(i);

    int move = 0;
    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;

        int idx = find(q.begin(), q.end(), target) - q.begin();
        if (idx <= q.size() - idx) {
            while (idx--) {
                q.push_back(q.front());
                q.pop_front();
                move++;
            }
        } else {
            idx = q.size() - idx;
            while (idx--) {
                q.push_front(q.back());
                q.pop_back();
                move++;
            }
        }

        q.pop_front();
    }

    cout << move << '\n';
}