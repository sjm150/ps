#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int k = 0;
    for (int b = 1; b < n; b <<= 1) k++;
    vector<vector<int>> nums(k);
    for (int i = 0; i < n; i++) {
        int num = i;
        for (int b = 0; num; b++) {
            if (num % 2) nums[b].push_back(i);
            num /= 2;
        }
    }
    int t = 0;
    for (auto ns: nums) t = max(t, int(ns.size()));
    cout << k << '\n';
    cout << t << '\n';
    for (auto ns: nums) {
        int r = t;
        for (auto num: ns) {
            cout << num << ' ';
            r--;
        }
        int x = ns[0];
        while (r--) {
            x--;
            cout << x << ' ';
        }
        cout << '\n';
    }
}