#include <iostream>
#include <algorithm>

using namespace std;

struct Fnum { int freq; int appr; int num; };
int n, c;
pair<int, int> nums[1000];
Fnum fnums[1000];

bool cmp(Fnum& a, Fnum& b) {
    if (a.freq == b.freq) return a.appr < b.appr;
    return a.freq > b.freq;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums[i] = {num, i};
    }
    sort(nums, nums + n);
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || nums[i].first != nums[i - 1].first) {
            fnums[idx++] = Fnum {1, nums[i].second, nums[i].first};
        } else {
            fnums[idx - 1].freq++;
        }
    }
    sort(fnums, fnums + idx, cmp);
    for (int i = 0; i < idx; i++) {
        for (int j = 0; j < fnums[i].freq; j++) cout << fnums[i].num << ' ';
    }
    cout << '\n';
}