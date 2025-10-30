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
    void DFSsearch(TreeNode* &root, int &targetSum, bool &answer, int &pathSum){
        if(root == nullptr){
            return;
        }
        pathSum = pathSum + root -> val;

        if(pathSum == targetSum && root->left == nullptr && root->right == nullptr){
            answer = true;
            return;
        }

        DFSsearch(root->left, targetSum, answer, pathSum);
        DFSsearch(root->right, targetSum, answer, pathSum);
        pathSum = pathSum - root->val;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool answer = false;
        int pathSum = 0;
        DFSsearch(root, targetSum, answer, pathSum);

        return answer;
    }
};