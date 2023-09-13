#include <bits/stdc++.h>
using namespace std;

set<int> openg;
int pg[100000];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int g, p; cin >> g >> p;
    for (int i = 1; i <= g; i++) openg.insert(i);
    for (int i = 0; i < p; i++) cin >> pg[i];
    int cnt = 0;
    for (int i = 0; i < p; i++) {
        auto it = openg.upper_bound(pg[i]);
        if (it == openg.begin()) break;
        openg.erase(prev(it));
        cnt++;
    }
    cout << cnt << '\n';
}