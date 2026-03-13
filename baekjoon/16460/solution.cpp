#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s, p;
    int lim, n;
    cin >> s >> p >> lim >> n;
    vector<string> ans;
    while (n--) {
        string nm;
        char g;
        int d;
        cin >> nm >> g >> d;
        if (find(p.begin(), p.end(), g) != p.end() && d <= lim) ans.push_back(nm);
    }
    if (ans.empty()) {
        cout << "No one yet\n";
    } else {
        sort(ans.begin(), ans.end());
        for (auto &a: ans) cout << a << '\n';
    }
}