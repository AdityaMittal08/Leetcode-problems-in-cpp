#include <vector>
#include <queue>
using namespace std;
// Definition for a binary tree node.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector<int>> answer;
        if(!root) return answer;
        queue <TreeNode*> q;
        answer.push_back({root->val});
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size();
            vector<int>level;
            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front();
                if(node->left){
                    level.push_back(node->left->val);
                    q.push(node->left);
                }
                if(node -> right){
                    level.push_back(node -> right->val);
                    q.push(node->right);
                }
                q.pop();
            }
            if(level.size() != 0){
                answer.push_back(level);
            }
        }

        return answer;
    }
};