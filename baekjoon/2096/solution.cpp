#include <bits/stdc++.h>
using namespace std;

int num[3], maxs[3], mins[3];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    while (n--) {
        cin >> num[0] >> num[1] >> num[2];
        maxs[0] = max(maxs[0], maxs[1]);
        maxs[2] = max(maxs[1], maxs[2]);
        maxs[1] = max(maxs[0], maxs[2]);
        mins[0] = min(mins[0], mins[1]);
        mins[2] = min(mins[1], mins[2]);
        mins[1] = min(mins[0], mins[2]);
        for (int i = 0; i < 3; i++) {
            maxs[i] += num[i];
            mins[i] += num[i];
        }
    }
    cout << max(maxs[0], max(maxs[1], maxs[2])) << ' ' << min(mins[0], min(mins[1], mins[2])) << '\n';
}