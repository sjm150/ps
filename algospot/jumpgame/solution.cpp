#include <iostream>

using namespace std;

int n;
int grid[100][100];

bool route[100][100];

bool has_route();

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        cout << (has_route() ? "YES" : "NO") << endl;
    }
}

bool has_route() {
    route[n - 1][n - 1] = true;
    for (int k = 2 * n - 3; k >= 0; k--) {
        if (k < n) {
            for (int i = k; i >= 0; i--) {
                int j = k - i;

                route[i][j] = false;
                int jump = grid[i][j];
                if (i + jump < n && route[i + jump][j]) route[i][j] = true;
                if (j + jump < n && route[i][j + jump]) route[i][j] = true;
            }
        } else {
            for (int i = n - 1; i >= k - n + 1; i--) {
                int j = k - i;

                route[i][j] = false;
                int jump = grid[i][j];
                if (i + jump < n && route[i + jump][j]) route[i][j] = true;
                if (j + jump < n && route[i][j + jump]) route[i][j] = true;
            }
        }
    }

    return route[0][0];
}