#include <string>
#include <vector>

using namespace std;

int count(vector<int> numbers, int target);

int solution(vector<int> numbers, int target) {
    int answer = 0;
    return count(numbers, target);
}

int count(vector<int> numbers, int target) {
    if (numbers.empty()) return target == 0;
    
    int number = numbers.back();
    numbers.pop_back();
    
    int ret = count(numbers, target + number) + count(numbers, target - number);
    numbers.push_back(number);
    return ret;
}