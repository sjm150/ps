#include <iostream>

#define R 0
#define G 1
#define B 2
#define RG 3

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int n;
int color[100][100];
bool visited[100][100];

void dfs(int x, int y, int type) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny]) {
            if ((type == RG && color[nx][ny] <= 1) || type == color[nx][ny]) {
                dfs(nx, ny, type);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            switch (line[j]) {
                case 'R':
                    color[i][j] = R;
                    break;
                case 'G':
                    color[i][j] = G;
                    break;
                case 'B':
                    color[i][j] = B;
                    break;
            }
        }
    }

    int count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(i, j, color[i][j]);
                count1++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                int type = color[i][j] == B ? B : RG;
                dfs(i, j, type);
                count2++;
            }
        }
    }

    cout << count1 << " " << count2 << '\n';
}