#include <iostream>
#include <cmath>

using namespace std;

int N, K;
int prefer[500];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> prefer[i];
    }

    double min = UINT64_MAX;
    for (int k = K; k <= N; k++) {
        for (int i = 0; i < N - k + 1; i++) {
            int sum = 0;
            for (int j = 0; j < k; j++) sum += prefer[i + j];

            double m = sum / (double)k;

            double sum_var = 0;
            for (int j = 0; j < k; j++) {
                double diff = prefer[i + j] - m;
                sum_var += diff * diff;
            }

            double stdev = sqrt(sum_var / k);

            if (stdev < min) min = stdev;
        }
    }

    cout << min << endl;
}