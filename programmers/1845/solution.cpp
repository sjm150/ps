#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums) {
    int size = nums.size();
    int species = 0;
    set<int> s;
    for (int num: nums) {
        auto it = s.find(num);
        if (it == s.end()) {
            s.insert(num);
            species++;
        }
    }
    return min(size / 2, species);
}