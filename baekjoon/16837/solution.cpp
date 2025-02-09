#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    double d; cin >> d;
    cout << setprecision(10) << max(d * sqrt(2), int(d) + 1.) << '\n';
}