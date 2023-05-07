#include <string>
#include <vector>

using namespace std;

vector<vector<int>> sel = {
    {1, 2, 3, 4, 5},
    {2, 1, 2, 3, 2, 4, 2, 5},
    {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
};

vector<int> solution(vector<int> answers) {
    int score[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < answers.size(); j++) {
            int mod = sel[i].size();
            if (sel[i][j % mod] == answers[j]) score[i]++;
        }
    }
    
    int max_score = max(score[0], max(score[1], score[2]));
    vector<int> max_scorer;
    for (int i = 0; i < 3; i++) {
        if (score[i] == max_score) max_scorer.push_back(i + 1);
    }
    return max_scorer;
}