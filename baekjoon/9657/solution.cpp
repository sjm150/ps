#include <bits/stdc++.h>
using namespace std;

bool wins[1001];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    wins[0] = wins[2] = false;
    wins[1] = wins[3] = wins[4] = true;
    for (int i = 5; i <= n; i++) wins[i] = !(wins[i - 1] && wins[i - 3] && wins[i - 4]);
    if (wins[n]) cout << "SK\n";
    else cout << "CY\n";
}