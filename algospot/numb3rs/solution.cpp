#include <iostream>
#include <iomanip>

using namespace std;

int n, d, p, t;
bool edge[50][50];
int edge_count[50];

double hide_prob_cache[50][100];

double hide_prob(int village, int day);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << setprecision(10);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        cin >> n >> d >> p;
        for (int i = 0; i < n; i++) {
            edge_count[i] = 0;
            for (int j = 0; j < n; j++) {
                cin >> edge[i][j];
                edge_count[i] += edge[i][j];
            }
            for (int j = 0; j <= d; j++) {
                hide_prob_cache[i][j] = -1;
            }
        }

        cin >> t;
        for (int i = 0; i < t; i++) {
            int q;
            cin >> q;

            cout << hide_prob(q, d) << " ";
        }
        cout << endl;
    }
}

double hide_prob(int village, int day) {
    if (day == 0) return village == p ? 1 : 0;

    double& cache = hide_prob_cache[village][day - 1];
    if (cache >= -0.5) return cache;

    cache = 0;
    for (int prev = 0; prev < n; prev++) {
        if (edge[village][prev]) {
            cache += hide_prob(prev, day - 1) / edge_count[prev];
        }
    }

    return cache;
}