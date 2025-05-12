#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n);
        for (int &x: x) cin >> x;
        cout << 2 * (*max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end())) << '\n';
    }
}