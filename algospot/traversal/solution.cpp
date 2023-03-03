#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_postorder(vector<int>& preorder, vector<int>& inorder);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        int n, temp;
        vector<int> preorder, inorder;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            preorder.push_back(temp);
        }
        for (int i = 0; i < n; i++) {
            cin >> temp;
            inorder.push_back(temp);
        }

        print_postorder(preorder, inorder);
        cout << endl;
    }
}

void print_postorder(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) return;

    int root = preorder.front();
    int inorder_root_idx = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    
    vector<int> preorder_left = vector<int>(preorder.begin() + 1, preorder.begin() + inorder_root_idx + 1);
    vector<int> preorder_right = vector<int>(preorder.begin() + inorder_root_idx + 1, preorder.end());
    vector<int> inorder_left = vector<int>(inorder.begin(), inorder.begin() + inorder_root_idx);
    vector<int> inorder_right = vector<int>(inorder.begin() + inorder_root_idx + 1, inorder.end());

    print_postorder(preorder_left, inorder_left);
    print_postorder(preorder_right, inorder_right);
    cout << root << " ";
}