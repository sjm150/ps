#include <iostream>

using namespace std;

const int cover_dy[4][2] = {{1, 1}, {1, 1}, {1, 0}, {1, 0}};
const int cover_dx[4][2] = {{-1, 0}, {0, 1}, {1, 1}, {0, 1}};

bool is_covered[20][20];

int h, w;

int count_cases(int y, int x);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        cin >> h >> w;
        int not_covered = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char input;
                cin >> input;

                if (input == '#') {
                    is_covered[i][j] = true;
                } else if (input == '.') {
                    is_covered[i][j] = false;
                    not_covered++;
                }
            }
        }

        if (not_covered % 3 == 0) {
            cout << count_cases(0, 0) << endl;
        } else {
            cout << 0 << endl;
        }
    }
}

int count_cases(int y, int x) {
    if (y >= h) return 1;
    if (x >= w) return count_cases(y + 1, 0);
    if (is_covered[y][x]) return count_cases(y, x + 1);

    int cases = 0;

    for (int d = 0; d < 4; d++) {
        int next_y0 = y + cover_dy[d][0];
        if (next_y0 < 0 || h <= next_y0) continue;
        int next_x0 = x + cover_dx[d][0];
        if (next_x0 < 0 || w <= next_x0) continue;
        int next_y1 = y + cover_dy[d][1];
        if (next_y1 < 0 || h <= next_y1) continue;
        int next_x1 = x + cover_dx[d][1];
        if (next_x1 < 0 || w <= next_x1) continue;

        if (!is_covered[next_y0][next_x0] && !is_covered[next_y1][next_x1]) {
            is_covered[y][x] = is_covered[next_y0][next_x0] = is_covered[next_y1][next_x1] = true;
            cases += count_cases(y, x + 1);
            is_covered[y][x] = is_covered[next_y0][next_x0] = is_covered[next_y1][next_x1] = false;
        }
    }

    return cases;
}