#include <iostream>
#include <vector>

using namespace std;

typedef struct FenwickTree {
    vector<int> range_sum;

    FenwickTree(int n) {
        range_sum = vector<int>(n + 1);
    }

    int sum(int until) {
        int ret = 0;
        int pos = until + 1;
        while (pos > 0) {
            ret += range_sum[pos];
            pos &= (pos - 1);
        }
        return ret;
    }

    void add(int idx, int val) {
        int pos = idx + 1;
        while (pos < range_sum.size()) {
            range_sum[pos] += val;
            pos += (pos & -pos);
        }
    }
} ftree_t;

long long count_move(vector<int>& arr);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        cout << count_move(arr) << '\n';
    }
}

long long count_move(vector<int>& arr) {
    long long count = 0;
    ftree_t ft(1000000);
    for (int num: arr) {
        count += ft.sum(999999) - ft.sum(num);
        ft.add(num, 1);
    }

    return count;
}