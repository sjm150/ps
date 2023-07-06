#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long int nums[100000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums, nums + n);
    long long int max_num = nums[0];
    int cnt = 1, max_cnt = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1]) {
            cnt++;
        } else {
            if (max_cnt < cnt) {
                max_num = nums[i - 1];
                max_cnt = cnt;
            }
            cnt = 1;
        }
    }
    if (max_cnt < cnt) max_num = nums[n - 1];
    cout << max_num << '\n';
}