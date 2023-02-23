#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double case_cache[1001][1001];

double count_cases(int n, int m);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << setprecision(10);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                case_cache[i][j] = -1;
            }
        }

        cout << count_cases(n, m) << endl;
    }
}

double count_cases(int n, int m) {
    if (n <= m) return 1;
    if (n > 2 * m) return 0;
    if (m == 0) return 0;

    double& cache = case_cache[n][m];
    if (cache >= 0) return cache;

    return cache = (count_cases(n - 1, m - 1) + 3 * count_cases(n - 2, m - 1)) / 4;
}