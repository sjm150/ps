#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long int nums[1000000];

long long int rev(long long int x) {
    long long int rev_x = 0;
    while (x) {
        rev_x = rev_x * 10 + x % 10;
        x /= 10;
    }
    return rev_x;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long int num;
        cin >> num;
        nums[i] = rev(num);
    }
    sort(nums, nums + n);
    for (int i = 0; i < n; i++) cout << nums[i] << '\n';
}