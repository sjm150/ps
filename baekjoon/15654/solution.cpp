#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int nums[8];
bool sel[8];
vector<int> order;

void print_sel() {
    for (int num: order) cout << num << ' ';
    cout << '\n';
}

void select(int selected) {
    if (selected == m) {
        print_sel();
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!sel[i]) {
            sel[i] = true;
            order.emplace_back(nums[i]);
            select(selected + 1);
            sel[i] = false;
            order.pop_back();
        }
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