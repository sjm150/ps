#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> numstr;
    for (int num: numbers) numstr.push_back(to_string(num));
    
    sort(numstr.begin(), numstr.end(),
         [](string& a, string& b) {
             return stoi(a + b) > stoi(b + a);
         }
    );
    
    if (numstr[0] == "0") return "0";
    string maxstr = "";
    for (string& num: numstr) maxstr += num;
    return maxstr;
}