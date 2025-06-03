#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        vector<int> e;
        for (int i = 0; i < 7; i++) {
            int a;
            cin >> a;
            if (a % 2 == 0) e.push_back(a);
        }
        cout << accumulate(e.begin(), e.end(), 0) << ' ' << *min_element(e.begin(), e.end()) << '\n';
    }
}