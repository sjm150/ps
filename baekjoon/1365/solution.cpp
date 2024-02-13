#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        auto it = lower_bound(lis.begin(), lis.end(), c);
        if (it == lis.end()) lis.push_back(c);
        else *it = c;
    }
    cout << n - lis.size() << '\n';
}