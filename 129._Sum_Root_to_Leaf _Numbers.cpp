#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private: 
    void preOrderTraversal(TreeNode* &root, vector<string> &storage, string &s){
        if(root == nullptr){
            return;
        }
        s += to_string(root->val);
        if(root->left == nullptr && root->right == nullptr){
            storage.push_back(s);
        }
        preOrderTraversal(root->left, storage, s);
        preOrderTraversal(root->right, storage, s);

        s.pop_back();
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<string> storage;
        string s = "";
        preOrderTraversal(root, storage, s);
        int answer = 0;
        for(int i = 0; i < storage.size(); i++){
            int add = std::stoi(storage[i]);
            answer += add;
        }

        return answer;
    }
};