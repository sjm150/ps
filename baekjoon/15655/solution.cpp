#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int nums[8];
bool sel[8];

void print() {
    for (int i = 0; i < n; i++) {
        if(sel[i]) cout << nums[i] << ' ';
    }
    cout << '\n';
}

void select(int i, int selected) {
    if (selected == m) {
        print();
        return;
    }
    if (i == n) return;
    sel[i] = true;
    select(i + 1, selected + 1);
    sel[i] = false;
    select(i + 1, selected);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums, nums + n);
    select(0, 0);
}