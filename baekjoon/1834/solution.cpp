#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    cout << (long long)(n + 1) * n * (n - 1) / 2 << '\n';
}