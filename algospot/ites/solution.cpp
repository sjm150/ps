#include <iostream>
#include <queue>

using namespace std;

int k, n;
unsigned curr_a;

int next_sig();
int count_subseq_with(int sum);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        cin >> k >> n;
        curr_a = 1983;

        cout << count_subseq_with(k) << endl;
    }
}

int next_sig() {
    int sig = curr_a % 10000u + 1;
    curr_a = curr_a * 214013u + 2531011u;
    return sig;
}

int count_subseq_with(int sum) {
    int count = 0;

    queue<int> subseq;
    int curr_sum = 0;

    int to = 0;
    for (int from = 0; from < n; from++) {
        while (curr_sum < k && to < n) {
            int sig = next_sig();
            curr_sum += sig;
            subseq.push(sig);
            to++;
        }

        if (curr_sum == k) count++;

        curr_sum -= subseq.front();
        subseq.pop();
    }

    return count;
}