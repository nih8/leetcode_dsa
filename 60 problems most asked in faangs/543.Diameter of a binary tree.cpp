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
    int maxx=0;
    int lol(TreeNode*root){
         if(!root)return 0;
        int max1 = lol(root->left);
        int max2 = lol(root->right);
        maxx = max(max1+max2,maxx);
        return 1+max(max1,max2);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        lol(root);
        return maxx;
    }
};