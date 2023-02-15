#include <iostream>
#include <vector>

using namespace std;

int push_needed[16];
const bool switch_linked[10][16] = {
    {true, true, true, false,},
    {false, false, false, true, false, false, false, true, false, true, false, true, false,},
    {false, false, false, false, true, false, false, false, false, false, true, false, false, false, true, true},
    {true, false, false, false, true, true, true, true, false,},
    {false, false, false, false, false, false, true, true, true, false, true, false, true, false,},
    {true, false, true, false, false, false, false, false, false, false, false, false, false, false, true, true},
    {false, false, false, true, false, false, false, false, false, false, false, false, false, false, true, true},
    {false, false, false, false, true, true, false, true, false, false, false, false, false, false, true, true},
    {false, true, true, true, true, true, false,},
    {false, false, false, true, true, true, false, false, false, true, false, false, false, true, false,}
};

int count_push_min(int switch_num);
bool is_synced();
void push(int switch_num);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        for (int i = 0; i < 16; i++) {
            int temp;
            cin >> temp;
            push_needed[i] = (12 - temp) / 3;
        }

        int min = count_push_min(0);
        cout << (min < INT16_MAX ? min : -1) << endl;
    }
}

int count_push_min(int switch_num) {
    if (switch_num >= 10) {
        if (is_synced()) return 0;
        else return INT16_MAX;
    }

    int current_min = INT16_MAX;

    for (int i = 0; i < 4; i++) {
        current_min = min(current_min, count_push_min(switch_num + 1) + i);
        push(switch_num);
    }

    return current_min;
}

bool is_synced() {
    for (int i = 0; i < 16; i++) {
        if (push_needed[i] != 0) return false;
    }

    return true;
}

void push(int switch_num) {
    for (int i = 0; i < 16; i++) {
        if (switch_linked[switch_num][i]) {
            push_needed[i]--;
            if (push_needed[i] < 0) push_needed[i] += 4;
        }
    }
}