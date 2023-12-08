#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    while (true) {
        int n; cin >> n;
        if (n < 0) break;
        int sum = 0;
        vector<int> divs;
        for (int i = 1; i < n; i++) {
            if (n % i) continue;
            sum += i;
            divs.push_back(i);
        }
        if (sum == n) {
            cout << n << " = " << divs[0];
            for (int i = 1; i < divs.size(); i++) cout << " + " << divs[i];
            cout << '\n';
        } else {
            cout << n << " is NOT perfect.\n";
        }
    }
}