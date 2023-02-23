#include <iostream>

using namespace std;

#define MOD 10000000

int case_cache[101][101];

int count_cases(int sel, int remain);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        int n;
        cin >> n;

        cout << count_cases(0, n) << endl;
    }
}

int count_cases(int sel, int remain) {
    if (remain == 0) return 1;

    int& cache = case_cache[sel][remain];
    if (cache > 0) return cache;

    for (int i = 1; i <= remain; i++) {
        int coef = sel == 0 ? 1 : sel + i - 1;
        cache += coef * count_cases(i, remain - i) % MOD;
    }

    cache %= MOD;
    return cache;
}