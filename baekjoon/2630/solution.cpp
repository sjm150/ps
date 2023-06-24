#include <iostream>

using namespace std;

int paper[128][128];
int count[2];

void get_count(int x, int y, int n) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (paper[i][j] != paper[x][y]) {
                for (int nx = x; nx < x + n; nx += (n / 2)) {
                    for (int ny = y; ny < y + n; ny += (n / 2)) {
                        get_count(nx, ny, n / 2);
                    }
                }
                return;
            }
        }
    }
    count[paper[x][y]]++;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    get_count(0, 0, n);
    cout << count[0] << '\n';
    cout << count[1] << '\n';
}