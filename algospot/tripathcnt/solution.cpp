#include <iostream>

using namespace std;

int n;
int triangle[100][100];

int path_sum_cache[100][100];
int max_num_cache[100][100];

int max_path_sum(int i, int j);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> triangle[i][j];
                path_sum_cache[i][j] = max_num_cache[i][j] = 0;
            }
        }

        max_path_sum(0, 0);
        cout << max_num_cache[0][0] << endl;
    }
}

int max_path_sum(int i, int j) {
    if (i == n - 1) {
        max_num_cache[i][j] = 1;
        return triangle[i][j];
    }

    int& sum_cache = path_sum_cache[i][j];
    int& num_cache = max_num_cache[i][j];
    if (sum_cache > 0) return sum_cache;

    int next_sum1 = max_path_sum(i + 1, j);
    int next_sum2 = max_path_sum(i + 1, j + 1);
    sum_cache = next_sum1;
    num_cache = max_num_cache[i + 1][j];
    if (sum_cache < next_sum2) {
        sum_cache = next_sum2;
        num_cache = max_num_cache[i + 1][j + 1];
    } else if (sum_cache == next_sum2) {
        num_cache += max_num_cache[i + 1][j + 1];
    }

    sum_cache += triangle[i][j];
    return sum_cache;
}