#include <iostream>
#include <cstddef>

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
    bool evaluateTree(TreeNode* root) {
        if(root == NULL) return true;
        
        if(root->left == NULL && root->right == NULL) return root->val;

        if(root->val == 3) return evaluateTree(root->left) && evaluateTree(root->right);
        return evaluateTree(root->left) || evaluateTree(root->right);
    }
};

int main() {
    Solution solution;
    TreeNode * root = new TreeNode(2);
    TreeNode* c1 = new TreeNode(1);
    TreeNode* c2 = new TreeNode(0);
    root->left = c1;
    root->right = c2;

    cout << solution.evaluateTree(root) << endl;
    return 0;
}
