#include<bits/stdc++.h>
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
    TreeNode* invertTree(TreeNode* root) {

        if(root){
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left,root->right);
        }
        return root;

    }
};

void inOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main()
{
        // Input Tree:
    //       4
    //      / \
    //     2   7
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution sol;
    sol.invertTree(root);
    inOrder(root);
}
