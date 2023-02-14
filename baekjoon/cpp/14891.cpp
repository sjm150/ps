#include <iostream>
#include <bitset>

using namespace std;

const int right_sign = 0b0010'0000;
const int left_sign  = 0b0000'0010;

const int top_sign = 0b1000'0000;

bool rotate_together(int l, int r);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int gear[4] = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++) {
        char c;
        for (int j = 0; j < 7; j++) {
            cin >> c;
            gear[i] |= c - '0';
            gear[i] = gear[i] << 1;
        }
        cin >> c;
        gear[i] |= c - '0';
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int gear_idx, dir;
        cin >> gear_idx >> dir;
        gear_idx--;

        int rotate[4] = {0, 0, 0, 0};
        rotate[gear_idx] = dir;
        for (int j = gear_idx - 1; j >= 0; j--) {
            if (rotate[j+1] != 0 && rotate_together(gear[j], gear[j+1])) {
                rotate[j] = -rotate[j+1];
            }
        }
        for (int j = gear_idx + 1; j < 4; j++) {
            if (rotate[j-1] != 0 && rotate_together(gear[j-1], gear[j])) {
                rotate[j] = -rotate[j-1];
            }
        }

        for (int j = 0; j < 4; j++) {
            if (rotate[j] < 0) {
                gear[j] = gear[j] << 1 | gear[j] >> 7;
            } else if (rotate[j] > 0) {
                gear[j] = gear[j] << 7 | gear[j] >> 1;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 4; i++) {
        result += (gear[i] & top_sign) >> 3;
        result = result >> 1;
    }

    cout << result << endl;
}

bool rotate_together(int l, int r) {
    return ((l & right_sign) > 0) != ((r & left_sign) > 0);
}