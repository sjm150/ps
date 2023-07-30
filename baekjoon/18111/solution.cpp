#include <iostream>
using namespace std;

int land[500][500];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m, b; cin >> n >> m >> b;
    int maxh = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> land[i][j];
            maxh += land[i][j];
        }
    }
    maxh = (maxh + b) / (n * m);
    int mint = INT32_MAX;
    int minh = 0;
    for (int h = maxh; h >= 0; h--) {
        int t = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (h >= land[i][j]) t += h - land[i][j];
                else t += 2 * (land[i][j] - h);
            }
        }
        if (t < mint) {
            mint = t;
            minh = h;
        }
    }
    cout << mint << ' ' << minh << '\n';
}