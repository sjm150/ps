#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> lis;
        while (n--) {
            int k;
            cin >> k;
            auto it = lower_bound(lis.begin(), lis.end(), k);
            if (it == lis.end()) lis.push_back(k);
            else *it = k;
        }
        cout << lis.size() << '\n';
    }
}