#include <iostream>

using namespace std;

int n, s;
int nums[20];

int num;
void get_num(int i, int sum) {
    if (i == n) {
        if (sum == s) num++;
        return;
    }
    get_num(i + 1, sum);
    get_num(i + 1, sum + nums[i]);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> nums[i];
    get_num(0, 0);
    if (s == 0) num--;
    cout << num << '\n';
}