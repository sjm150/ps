#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++) {
        string& curr = phone_book[i];
        if (curr == phone_book[i + 1].substr(0, curr.size())) return false;
    }
    
    return true;
}