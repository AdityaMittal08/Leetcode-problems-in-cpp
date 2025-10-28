#include <vector>
#include <unordered_map>
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
    TreeNode* buildTree(vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map <int, int> &inMap){

        if(inStart > inEnd || postStart > postEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;
        
        root->right = buildTree(postorder, inRoot + 1 , inEnd, postStart + numsLeft, postEnd -1, inMap);
        root->left = buildTree(postorder, inStart, inRoot - 1, postStart, postStart + numsLeft - 1, inMap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map <int, int> inMap;

        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        return buildTree(postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, inMap);
    }
};