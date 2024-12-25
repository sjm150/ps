#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, d; cin >> n >> d;
        vector<int> ans = {1};
        if (d % 3 == 0 || n >= 3) ans.push_back(3);
        if (d == 5) ans.push_back(5);
        if (d == 7 || n >= 3) ans.push_back(7);
        if (d == 9 || n >= 6 || (d % 3 == 0 && n >= 3)) ans.push_back(9);
        for (int a: ans) cout << a << ' ';
        cout << '\n';
    }
}