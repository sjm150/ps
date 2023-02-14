#include <iostream>

using namespace std;

int board[9][9];
bool row_used[9][9];
bool col_used[9][9];
bool cel_used[3][3][9];

void insert(int i, int j, int val);
void erase(int i, int j);
bool process(int i, int j);
void print();
pair<int, int> next_empty(int i, int j);

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int val;
            cin >> val;

            if (val > 0) insert(i, j, val);
        }
    }

    auto next = next_empty(0, -1);
    process(next.first, next.second);
    print();
}

void insert(int i, int j, int val) {
    board[i][j] = val;
    int index = val - 1;

    row_used[i][index] = true;
    col_used[j][index] = true;
    cel_used[i/3][j/3][index] = true;
}

void erase(int i, int j) {
    int index = board[i][j] - 1;

    board[i][j] = 0;
    row_used[i][index] = false;
    col_used[j][index] = false;
    cel_used[i/3][j/3][index] = false;
}

bool process(int i, int j) {
    if (i == -1) return true;

    auto next = next_empty(i, j);

    for (int val = 1; val <= 9; val++) {
        if (!row_used[i][val-1] && !col_used[j][val-1] && !cel_used[i/3][j/3][val-1]) {
            insert(i, j, val);

            if (process(next.first, next.second)) return true;

            erase(i, j);
        }
    }

    return false;
}

pair<int, int> next_empty(int i, int j) {
    int next_i = i, next_j = j+1;
    for (; next_i < 9; next_i++) {
        for (; next_j < 9; next_j++) {
            if (board[next_i][next_j] == 0) {
                return make_pair(next_i, next_j);
            }
        }

        next_j = 0;
    }

    return make_pair(-1, -1);
}

void print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << board[i][8] << endl;
    }
}
