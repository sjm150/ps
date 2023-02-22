#include <iostream>

using namespace std;

int n, m;
int seq_a[100], seq_b[100];
int max_len_cache[101][101];

int max_len(int from_a, int from_b);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> seq_a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> seq_b[i];
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                max_len_cache[i][j] = -1;
            }
        }

        int len = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                len = max(len, max_len(i, j));
            }
        }

        cout << len << endl;
    }
}

int max_len(int from_a, int from_b) {
    if (from_a == n && from_b == m) return 0;

    int& cache = max_len_cache[from_a][from_b];
    if (cache >= 0) return cache;

    for (int i = from_a + 1; i <= n; i++) {
        if ((i == n && (from_b == m || seq_a[from_a] < seq_b[from_b])) ||
            (seq_a[from_a] < (from_b == m ? seq_a[i] : min(seq_a[i], seq_b[from_b])))) {
            cache = max(cache, max_len(i, from_b) + 1);
        }
    }
    for (int i = from_b + 1; i <= m; i++) {
        if ((i == m && (from_a == n || seq_b[from_b] < seq_a[from_a])) ||
            (seq_b[from_b] < (from_a == n ? seq_b[i] : min(seq_a[from_a], seq_b[i])))) {
            cache = max(cache, max_len(from_a, i) + 1);
        }
    }

    return cache;
}
