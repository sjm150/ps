#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int nums[8];
bool sel[8];
int order[8];

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
        if (i != 0 && !sel[i - 1] && nums[i] == nums[i - 1]) continue;
        if (sel[i]) continue;
        order[selected] = nums[i];
        sel[i] = true;
        select(selected + 1);
        sel[i] = false;
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