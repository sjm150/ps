#include <iostream>

using namespace std;

int n;
int height[20000];

int get_max_area(int left, int right);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> height[i];
        }

        cout << get_max_area(0, n) << endl;
    }
}

// inclusive left, exclusive right
int get_max_area(int left, int right) {
    if (right - left <= 1) {
        return height[left];
    }

    int mid = (left + right) / 2;

    int max_area = max(get_max_area(left, mid), get_max_area(mid, right));

    int mid_left = mid - 1;
    int mid_right = mid + 1;
    int min_height = min(height[mid_left], height[mid_right - 1]);
    max_area = max(max_area, 2 * min_height);
    
    while (left < mid_left || mid_right < right) {
        if (mid_right < right && (left == mid_left || height[mid_left - 1] < height[mid_right])) {
            min_height = min(min_height, height[mid_right]);
            mid_right++;
        } else {
            mid_left--;
            min_height = min(min_height, height[mid_left]);
        }

        max_area = max(max_area, min_height * (mid_right - mid_left));
    }

    return max_area;
}