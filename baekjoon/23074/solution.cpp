#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> ans = {1};
    for (int i = 2; i <= n; i++) ans.push_back(i / 2);
    cout << ans.back() << '\n';
    for (int a: ans) cout << a << ' ';
    cout << '\n';
}