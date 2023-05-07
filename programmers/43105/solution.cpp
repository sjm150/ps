#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> sum(triangle);
    for (int i = 1; i < triangle.size(); i++) {
        triangle[i][0] += triangle[i - 1][0];
        triangle[i][triangle[i].size() - 1] += triangle[i - 1][triangle[i - 1].size() - 1];
        for (int j = 1; j < triangle[i].size() - 1; j++) {
            triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
    }
    
    int maxnum = 0;
    for (int num: triangle[triangle.size() - 1]) {
        maxnum = max(maxnum, num);
    }
    return maxnum;
}