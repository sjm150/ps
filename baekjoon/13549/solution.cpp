#include <iostream>
#include <queue>

#define E 100001

using namespace std;

int times[E];

void push_in(int x, int t, int k, queue<int>& q) {
    do {
        times[x] = t;
        q.push(x);
        x *= 2;
    } while (x < min(2 * k, E) && times[x] == 0);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    push_in(n, 1, k, q);
    while (!q.empty()) {
        int curr = q.front();
        int t = times[curr];
        q.pop();

        if (curr == k) break;

        if (curr >= 1 && times[curr - 1] == 0) push_in(curr - 1, t + 1, k, q);
        if (curr + 1 < E && times[curr + 1] == 0) push_in(curr + 1, t + 1, k, q);
    }

    cout << times[k] - 1 << '\n';
}