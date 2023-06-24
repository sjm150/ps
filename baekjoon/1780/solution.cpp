#include <iostream>

#define MAX 2187

using namespace std;

int paper[MAX][MAX];
int countm1, count0, count1;

void count(int x0, int y0, int n) {
    int num = paper[x0][y0];
    for (int i = x0; i < x0 + n; i++) {
        for (int j = y0; j < y0 + n; j++) {
            if (num != paper[i][j]) {
                for (int nx = x0; nx < x0 + n; nx += (n / 3)) {
                    for (int ny = y0; ny < y0 + n; ny += (n / 3)) {
                        count(nx, ny, n / 3);
                    }
                }
                return;
            }
        }
    }

    switch (num) {
        case -1:
            countm1++;
            break;
        case 0:
            count0++;
            break;
        case 1:
            count1++;
            break;
    }
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
    count(0, 0, n);
    cout << countm1 << '\n';
    cout << count0 << '\n';
    cout << count1 << '\n';
}