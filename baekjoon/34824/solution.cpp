#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        string s;
        cin >> s;
        if (ans) continue;
        if (s == "yonsei") ans = 1;
        else if (s == "korea") ans = -1;
    }
    cout << "Yonsei " << (ans > 0 ? "Won!\n" : "Lost...\n");
}