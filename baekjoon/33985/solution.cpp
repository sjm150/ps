#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string t;
    cin >> t;
    cout << (t[0] == 'A' && t[n - 1] == 'B' ? "Yes\n" : "No\n");
}