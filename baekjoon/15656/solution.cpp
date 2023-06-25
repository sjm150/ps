#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int nums[7];
int order[7];

void print() {
    for (int i = 0; i < m; i++) cout << order[i] << ' ';
    cout << '\n';
}

void select(int selected) {
    if (selected == m) {
        print();
        return;
    }
    for (int i = 0; i < n; i++) {
        order[selected] = nums[i];
        select(selected + 1);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums, nums + n);
    select(0);
}