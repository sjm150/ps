#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, l; cin >> n >> l;
    int a; cin >> a;
    cout << a;
    deque<pi> dq;
    dq.emplace_back(0, a);
    for (int i = 1; i < n; i++) {
        cin >> a;
        while (!dq.empty() && dq.back().second > a) dq.pop_back();
        dq.emplace_back(i, a);
        if (dq.front().first < i - l + 1) dq.pop_front();
        cout << ' ' << dq.front().second;
    }
    cout << '\n';
}