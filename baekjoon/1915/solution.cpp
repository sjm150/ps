#include <iostream>

using namespace std;

int arr[1001][1001];
int len[1001][1001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string line;
        cin >> line;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = line[j - 1] - '0';
        }
    }
    int maxlen = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 1) {
                len[i][j] = min(len[i - 1][j - 1], min(len[i - 1][j], len[i][j - 1])) + 1;
                maxlen = max(maxlen, len[i][j]);
            }
        }
    }
    cout << maxlen * maxlen << '\n';
}