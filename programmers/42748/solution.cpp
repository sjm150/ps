#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto& cmd: commands) {
        int i = cmd[0], j = cmd[1], k = cmd[2];
        vector<int> clone;
        for (int idx = i - 1; idx < j; idx++) clone.push_back(array[idx]);
        sort(clone.begin(), clone.end());
        answer.push_back(clone[k - 1]);
    }
    return answer;
}