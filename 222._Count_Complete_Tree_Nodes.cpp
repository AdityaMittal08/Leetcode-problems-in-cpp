#include <cmath>
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
public:
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int countLeft = 0;
        int countRight = 0;
        TreeNode* leftTree = root, *rightTree = root;
        
        while(leftTree){
            countLeft++; 
            leftTree = leftTree->left;
        }
        while(rightTree){
            countRight++;
            rightTree = rightTree->right;
        }

        if(countLeft == countRight){
            return pow(2, countLeft) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};