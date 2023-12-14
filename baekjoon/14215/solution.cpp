#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int l[3]; cin >> l[0] >> l[1] >> l[2];
    sort(l, l + 3);
    cout << l[0] + l[1] + min(l[2], l[0] + l[1] - 1) << '\n';
}