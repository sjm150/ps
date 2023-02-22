#include <iostream>

using namespace std;

#define MAX 100000;

int n;
int nums[10000];
int min_score_cache[10000];

int min_score(int from);
int calculate(int from, int to);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        string line;
        cin >> line;
        n = line.length();
        for (int i = 0; i < n; i++) {
            nums[i] = line.at(i) - '0';
            min_score_cache[i] = -1;
        }

        cout << min_score(0) << endl;
    }
}

int min_score(int from) {
    if (from == n) return 0;
    if (from > n - 3) return MAX;

    int& cache = min_score_cache[from];
    if (cache > 0) return cache;

    cache = MAX;
    for (int next = from + 3; next <= n && next <= from + 5; next++) {
        cache = min(cache, min_score(next) + calculate(from, next));
    }

    return cache;
}

// inclusive from, exclusive to
int calculate(int from, int to) {
    bool result = true;
    for (int i = from + 1; i < to; i++) {
        if (nums[i - 1] != nums[i]) {
            result = false;
            break;
        }
    }
    if (result) return 1;

    result = true;
    int diff = nums[from + 1] - nums[from];
    for (int i = from + 2; i < to; i++) {
        if (nums[i] - nums[i - 1] != diff) {
            result = false;
            break;
        }
    }
    if (result) {
        if (diff == 1 || diff == -1) return 2;
        else return 5;
    }

    result = true;
    for (int i = from + 2; i < to; i++) {
        if (nums[i] != nums[i - 2]) {
            result = false;
            break;
        }
    }
    if (result) return 4;

    return 10;
}