#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    map<int, string> g = {{59, "F"}, {66, "D"}, {69, "D+"}, {76, "C"}, {79, "C+"}, {86, "B"}, {89, "B+"}, {96, "A"}, {100, "A+"}};
    int t;
    cin >> t;
    while (t--) {
        string a;
        int b;
        cin >> a >> b;
        cout << a << ' ' << g.lower_bound(b)->second << '\n';
    }
}