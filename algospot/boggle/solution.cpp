#include <iostream>

using namespace std;

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int board_size = 5;
const int max_word_len = 10;

char board[board_size][board_size];

bool has_word(const string& woid);
void compute_suffix_existence(const string& suffix, bool (&result)[board_size][board_size][max_word_len]);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        for (auto line: board) {
            cin >> line;
        }

        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            string word;
            cin >> word;

            cout << word << " " << (has_word(word) ? "YES" : "NO") << endl;
        }
    }
}

bool has_word(const string& word) {
    bool has_suffix[board_size][board_size][max_word_len] = {false, };

    for (int i = word.length() - 1; i >= 0; i--) {
        compute_suffix_existence(word.substr(i), has_suffix);
    }

    for (int x = 0; x < board_size; x++) {
        for (int y = 0; y < board_size; y++) {
            if (has_suffix[x][y][word.length() - 1]) {
                return true;
            }
        }
    }

    return false;
}

void compute_suffix_existence(const string& suffix, bool (&result)[board_size][board_size][max_word_len]) {
    for (int x = 0; x < board_size; x++) {
        for (int y = 0; y < board_size; y++) {
            if (suffix[0] == board[x][y]) {
                int len = suffix.length();

                if (len == 1) {
                    result[x][y][0] = true;
                } else {
                    for (int d = 0; d < 8; d++) {
                        int next_x = x + dx[d];
                        int next_y = y + dy[d];

                        if (next_x < 0 || board_size <= next_x) continue;
                        if (next_y < 0 || board_size <= next_y) continue;

                        if (result[next_x][next_y][len - 2] == true) {
                            result[x][y][len - 1] = true;
                        }
                    }
                }
            }
        }
    }
}