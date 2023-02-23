#include <iostream>

using namespace std;

#define MOD 1000000007

int case_cache[100];

int count_cases(int n);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        int n;
        cin >> n;

        if (n % 2 == 0) {
            cout << ((count_cases(n) - count_cases(n / 2) + MOD) % MOD - count_cases(n / 2 - 1) + MOD) % MOD << endl;
        } else {
            cout << (count_cases(n) - count_cases(n / 2) + MOD) % MOD << endl;
        }
    }
}

int count_cases(int n) {
    if (n <= 1) return 1;
    if (n == 2) return 2;

    int& cache = case_cache[n];
    if (cache > 0) return cache;

    cache = count_cases(n - 1) + count_cases(n - 2);
    if (cache >= MOD) cache %= MOD;

    return cache;
}