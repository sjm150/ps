#include <iostream>

using namespace std;

int pixel[64][64];

string quadtree(int x, int y, int n) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (pixel[i][j] != pixel[x][y]) {
                string res = "";
                for (int nx = x; nx < x + n; nx += n / 2) {
                    for (int ny = y; ny < y + n; ny += n / 2) {
                        res += quadtree(nx, ny, n / 2);
                    }
                }
                return "(" + res + ")";
            }
        }
    }
    return pixel[x][y] ? "1" : "0";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string buf;
        cin >> buf;
        for (int j = 0; j < n; j++) pixel[i][j] = buf[j] - '0';
    }
    cout << quadtree(0, 0, n) << "\n";
}