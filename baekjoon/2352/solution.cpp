#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> p(n);
    for (auto &p: p) cin >> p;

    vector<int> lis;
    for (int p: p) {
        auto it = upper_bound(lis.begin(), lis.end(), p);
        if (it == lis.end()) lis.push_back(p);
        else *it = p;
    }

    cout << lis.size() << '\n';
}