#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000000;

int n, s;
int sequence[100];

int min_err_sqr_cache[100][11];

int min_err_sqr(int from, int sel);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        cin >> n >> s;
        for (int i = 0; i < n; i++) {
            cin >> sequence[i];
            for (int j = 0; j <= s; j++) {
                min_err_sqr_cache[i][j] = -1;
            }
        }

        sort(sequence, sequence + n);

        cout << min_err_sqr(0, 0) << endl;
    }
}

int min_err_sqr(int from, int sel) {
    if (sel > s) return MAX;
    if (from == n) return 0;

    int& cache = min_err_sqr_cache[from][sel];
    if (cache >= 0) return cache;
    cache = MAX;

    int sum = 0;
    int sqr_sum = 0;
    for (int i = from; i < n; i++) {
        sum += sequence[i];
        sqr_sum += sequence[i] * sequence[i];
        int mean = int(double(sum) / (i - from + 1) + 0.5);

        cache = min(cache, min_err_sqr(i + 1, sel + 1) + sqr_sum - 2 * sum * mean + (i - from + 1) * mean * mean);
    }

    return cache;
}