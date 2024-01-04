#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    deque<int> qs;
    for (int i = 0; i < n; i++) {
        int b; cin >> b;
        if (a[i]) continue;
        qs.push_front(b);
    }
    
    int m; cin >> m;
    while (m--) {
        int c; cin >> c;
        qs.push_back(c);
        cout << qs.front() << ' ';
        qs.pop_front();
    }
}