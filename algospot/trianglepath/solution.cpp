#include <iostream>

using namespace std;

int n;
int triangle[100][100];

int path_sum_cache[100][100];

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
                path_sum_cache[i][j] = 0;
            }
        }

        cout << max_path_sum(0, 0) << endl;
    }
}

int max_path_sum(int i, int j) {
    if (i == n - 1) return triangle[i][j];

    int& cache = path_sum_cache[i][j];
    if (cache != 0) return cache;

    return cache = triangle[i][j] + max(
        max_path_sum(i + 1, j),
        max_path_sum(i + 1, j + 1)
    );
}