#include <vector>
#include <variant>
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
    void traversal(TreeNode* p, vector<variant<char, int>> &arr){
        if(p == NULL){
            arr.push_back('n');
            return;
        }
        traversal(p -> left, arr);
        traversal(p -> right, arr);
        arr.push_back(p->val);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<variant<char, int>> pTree;
        vector<variant<char, int>> qTree;
        traversal(p, pTree);
        traversal(q, qTree);
        return (pTree == qTree);
    }
};