#include <iostream>
#include <vector>

#define L 0
#define R 1
#define U 2
#define D 3

using namespace std;

int n;
int init[20][20];
int board[20][20];

void initialize() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = init[i][j];
        }
    }
}

void move(int d) {
    if (d == U || d == D) {
        for (int j = 0; j < n; j++) {
            if (d == U) {
                int idx = 0;
                int prev = -1;
                for (int i = 0; i < n; i++) {
                    if (board[i][j] == 0) continue;
                    if (prev == board[i][j]) {
                        board[idx++][j] = prev * 2;
                        prev = -1;
                    } else {
                        if (prev > 0) board[idx++][j] = prev;
                        prev = board[i][j];
                    }
                }
                if (prev > 0) board[idx++][j] = prev;
                while (idx < n) board[idx++][j] = 0;
            } else {
                int idx = n - 1;
                int prev = -1;
                for (int i = n - 1; i >= 0; i--) {
                    if (board[i][j] == 0) continue;
                    if (prev == board[i][j]) {
                        board[idx--][j] = prev * 2;
                        prev = -1;
                    } else {
                        if (prev > 0) board[idx--][j] = prev;
                        prev = board[i][j];
                    }
                }
                if (prev > 0) board[idx--][j] = prev;
                while (idx >= 0) board[idx--][j] = 0;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (d == L) {
                int jdx = 0;
                int prev = -1;
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 0) continue;
                    if (prev == board[i][j]) {
                        board[i][jdx++] = prev * 2;
                        prev = -1;
                    } else {
                        if (prev > 0) board[i][jdx++] = prev;
                        prev = board[i][j];
                    }
                }
                if (prev > 0) board[i][jdx++] = prev;
                while (jdx < n) board[i][jdx++] = 0;
            } else {
                int jdx = n - 1;
                int prev = -1;
                for (int j = n - 1; j >= 0; j--) {
                    if (board[i][j] == 0) continue;
                    if (prev == board[i][j]) {
                        board[i][jdx--] = prev * 2;
                        prev = -1;
                    } else {
                        if (prev > 0) board[i][jdx--] = prev;
                        prev = board[i][j];
                    }
                }
                if (prev > 0) board[i][jdx--] = prev;
                while (jdx >= 0) board[i][jdx--] = 0;
            }
        }
    }
}

int get_max() {
    int max_num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            max_num = max(max_num, board[i][j]);
        }
    }
    return max_num;
}

void next(vector<int>& p) {
    for (int i = 0; i < p.size(); i++) {
        p[i]++;
        if (p[i] == 4) p[i] = 0;
        else break;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> init[i][j];
        }
    }
    vector<int> p(5, 0);
    int max_num = 0;
    for (int i = 0; i < 1024; i++) {
        initialize();
        for (int d: p) move(d);
        max_num = max(max_num, get_max());
        next(p);
    }
    cout << max_num << '\n';
}