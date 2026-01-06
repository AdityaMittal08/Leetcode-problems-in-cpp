#include <vector>
#include <queue>
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
    int maxLevelSum(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        int res = 1;
        int maxSum = -(pow(2, 32) - 1);
        int level = 1;
        while(!q.empty()){
            int levelSize = q.size();
            int temp = 0;
            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front();
                temp += node->val;
                if(node -> left){
                    q.push(node->left);
                }
                if(node -> right){
                    q.push(node->right);
                }
                q.pop();
            }
            if(temp > maxSum){
                maxSum = temp;
                res = level;
            }
            level++;
        }

        return res;
    }
};