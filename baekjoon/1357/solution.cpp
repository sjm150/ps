#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string x, y;
    cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    string ans = to_string(stoi(x) + stoi(y));
    reverse(ans.begin(), ans.end());
    cout << stoi(ans) << '\n';
}