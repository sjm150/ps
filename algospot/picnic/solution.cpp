#include <iostream>

using namespace std;

int n;
bool is_friend[10][10];
bool is_matched[10];

int count_cases(int first);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        int m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                is_friend[i][j] = false;
            }
            is_matched[i] = false;
        }

        for (int i = 0; i < m; i++) {
            int no1, no2;
            cin >> no1 >> no2;

            is_friend[no1][no2] = is_friend[no2][no1] = true;
        }

        cout << count_cases(0) << endl;
    }
}

int count_cases(int first) {
    if (first >= n) return 1;
    if (is_matched[first]) return count_cases(first + 1);

    int cases = 0;

    for (int i = first + 1; i < n; i++) {
        if (!is_matched[i] && is_friend[first][i]) {
            is_matched[first] = is_matched[i] = true;
            cases += count_cases(first + 1);
            is_matched[first] = is_matched[i] = false;
        }
    }

    return cases;
}