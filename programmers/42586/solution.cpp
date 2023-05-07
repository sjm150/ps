#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> req_days;
    for (int i = 0; i < progresses.size(); i++) {
        int s = speeds[i];
        req_days.push_back((100 - progresses[i] + s - 1) / s);
    }
        
    vector<int> ans;
    ans.push_back(1);
    int std = req_days[0];
    for (int i = 1; i < req_days.size(); i++) {
        if (req_days[i] > std) {
            ans.push_back(1);
            std = req_days[i];
        } else {
           ans.back()++; 
        }
    }
    return ans;
}