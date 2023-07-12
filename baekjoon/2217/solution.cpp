#include <iostream>
#include <algorithm>

using namespace std;

int lim[100000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> lim[i];
    sort(lim, lim + n, greater<int>());
    int maxlim = 0;
    for (int i = 0; i < n; i++) maxlim = max(maxlim, lim[i] * (i + 1));
    cout << maxlim << '\n';
}