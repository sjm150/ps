#include <iostream>
#include <queue>

using namespace std;

const int a0 = 1983;
const int mod = 20090711;

int curr_a, a, b;
int next_a() {
    int ret = curr_a;
    curr_a = (curr_a * (long long)(a) + b) % mod;
    return ret;
}

int n;
int median_sum();

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        curr_a = a0;
        cin >> n >> a >> b;

        cout << median_sum() << endl;
    }
}

int median_sum() {
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int sum = 0, size = 0;
    bool is_odd = false;

    while (size < n) {
        if (is_odd) min_heap.emplace(next_a());
        else max_heap.emplace(next_a());
        is_odd = !is_odd;
        size++;

        if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
            int max_heap_top = max_heap.top();
            int min_heap_top = min_heap.top();
            max_heap.pop();
            min_heap.pop();

            min_heap.emplace(max_heap_top);
            max_heap.emplace(min_heap_top);
        }

        sum = (sum + max_heap.top()) % mod;
    }

    return sum;
}