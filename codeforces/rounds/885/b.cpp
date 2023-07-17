#include <iostream>

using namespace std;

int c[200001];
int last[200001];
int maxstep[200001][2];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 1; i <= k; i++) {
            last[i] = maxstep[i][0] = maxstep[i][1] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int curr = c[i];
            int step = i - last[curr] - 1;
            if (maxstep[curr][0] < step) {
                maxstep[curr][1] = maxstep[curr][0];
                maxstep[curr][0] = step;
            } else if (maxstep[curr][1] < step) {
                maxstep[curr][1] = step;
            }
            last[curr] = i;
        }
        int ans = INT32_MAX;
        for (int i = 1; i <= k; i++) {
            int step = n + 1 - last[i] - 1;
            if (maxstep[i][0] < step) {
                maxstep[i][1] = maxstep[i][0];
                maxstep[i][0] = step;
            } else if (maxstep[i][1] < step) {
                maxstep[i][1] = step;
            }
            ans = min(ans, max(maxstep[i][0] / 2, maxstep[i][1]));
        }
        cout << ans << '\n';
    }
}