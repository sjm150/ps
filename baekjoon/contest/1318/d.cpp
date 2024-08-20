#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v;
    if (n == 8) v = {6, 4, 2, 8, 7, 1, 5, 3};
    else if (n == 9) v = {6, 4, 2, 8, 7, 1, 5, 9, 3};
    else {
        for (int i = 2; i <= n; i += 2) {
            if (i == 6 || i == 10) continue;
            v.push_back(i);
        }
        v.push_back(10);
        v.push_back(5);
        for (int i = 1; i <= n; i += 2) {
            if (i == 3 || i == 5) continue;
            v.push_back(i);
        }
        v.push_back(3);
        v.push_back(6);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) cout << v[j] << ' ';
        for (int j = 0; j < i; j++) cout << v[j] << ' ';
        cout << '\n';
    }
}