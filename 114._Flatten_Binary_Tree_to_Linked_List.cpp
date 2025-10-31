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
    void preOrderTraversal(TreeNode* &root, vector<int> &ans){
        if(root == nullptr){
            return;
        }
        ans.push_back(root->val);

        preOrderTraversal(root->left, ans);
        preOrderTraversal(root->right, ans);
    }
public:
    void flatten(TreeNode* root) {
        vector<int> ans;
        preOrderTraversal(root, ans);

        for(int i = 1; i < ans.size(); i++){
            TreeNode* name = new TreeNode(ans[i]);
            root->right = name;
            root->left = nullptr;
            root = root -> right;
        }
        return;
    }
};