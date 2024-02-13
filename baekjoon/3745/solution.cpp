#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    while (cin >> n) {
        vector<int> lis;
        while (n--) {
            int p; cin >> p;
            auto it = lower_bound(lis.begin(), lis.end(), p);
            if (it == lis.end()) lis.push_back(p);
            else *it = p;
        }
        cout << lis.size() << '\n';
    }
}