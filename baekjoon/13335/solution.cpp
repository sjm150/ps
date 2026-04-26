#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int a[1000];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, w, l; cin >> n >> w >> l;
    for (int i = 0; i < n; i++) cin >> a[i];
    int t = 1, cur = 0;
    queue<pi> q;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.front().second <= t) {
            cur -= q.front().first;
            q.pop();
        }
        while (q.size() == w || cur + a[i] > l) {
            t = q.front().second;
            cur -= q.front().first;
            q.pop();
        }
        cur += a[i];
        q.emplace(a[i], t + w);
        t++;
    }
    while (!q.empty()) {
        t = q.front().second;
        q.pop();
    }
    cout << t << '\n';
}