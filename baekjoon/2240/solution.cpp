#include <iostream>
using namespace std;

int drop[1001];
int earn[31][1001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t, w; cin >> t >> w;
    for (int i = 1; i <= t; i++) cin >> drop[i];
    for (int i = 1; i <= t; i++) {
        earn[0][i] = earn[0][i - 1];
        if (drop[i] == 1) earn[0][i]++;
    }
    for (int k = 1; k <= w; k++) {
        for (int i = k; i <= t; i++) {
            earn[k][i] = max(earn[k][i - 1], earn[k - 1][i - 1]);
            if (k % 2 + 1 == drop[i]) earn[k][i]++;
        }
    }
    int maxe = 0;
    for (int i = 0; i <= w; i++) maxe = max(maxe, earn[i][t]);
    cout << maxe << '\n';
}