#include <iostream>

using namespace std;

char grid[8][8];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int x = -1, y = -1;
        for (int i = 0; i < 8; i++) {
            string line;
            cin >> line;
            for (int j = 0; j < 8; j++) {
                grid[i][j] = line[j];
                if (x < 0 && grid[i][j] != '.') x = i, y = j;
            }
        }
        for (int i = x; i < 8; i++) {
            if (grid[i][y] == '.') break;
            cout << grid[i][y];
        }
        cout << '\n';
    }
}