#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<int> ans;
    for (int t = 1; t <= 5; t++) {
        string s;
        cin >> s;
        bool ok = false;
        for (int i = 0; i < int(s.size()) - 2; i++) {
            if (s.substr(i, 3) == "FBI") {
                ok = true;
                break;
            }
        }
        if (ok) ans.push_back(t);
    }
    if (ans.empty()) {
        cout << "HE GOT AWAY!\n";
    } else {
        for (int a: ans) cout << a << ' ';
        cout << '\n';
    }
}