#include <string>
#include <vector>

using namespace std;

int select(int sel_num, int k, vector<vector<int>>& dungeons, vector<bool> selected) {
    if (k == 0) return sel_num;
    int sel_max = sel_num;

    for (int i = 0; i < dungeons.size(); i++) {
        if (selected[i]) continue;
        int require = dungeons[i][0], use = dungeons[i][1];

        if (require <= k) {
            selected[i] = true;
            sel_max = max(sel_max, select(sel_num + 1, k - use, dungeons, selected));
            selected[i] = false;
        }
    }
    return sel_max;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> selected(dungeons.size(), false);
    return select(0, k, dungeons, selected);
}