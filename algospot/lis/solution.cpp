#include <iostream>

using namespace std;

int n;
int sequence[500];

int max_len_cache[500];

int max_len(int from);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> sequence[i];
            max_len_cache[i] = 0;
        }

        int len = 1;
        for (int i = 0; i < n; i++) {
            len = max(len, max_len(i));
        }

        cout << len << endl;
    }
}

int max_len(int from) {
    if (from == n - 1) return 1;

    int& cache = max_len_cache[from];
    if (cache > 0) return cache;

    int len = 1;
    for (int i = from + 1; i < n; i++) {
        if (sequence[from] < sequence[i]) {
            len = max(len, max_len(i) + 1);
        }
    }

    cache = len;
    return len;
}