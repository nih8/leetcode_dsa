#include<bits/stdc++.h>
using namespace std;

//https://www.youtube.com/watch?v=_-QHfMDde90 good video for understanding logic
 struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q){
            return root;
        }
        TreeNode * left = lowestCommonAncestor(root->left,p,q);
        TreeNode*right = lowestCommonAncestor(root->right,p,q);
        if(right && left){
            return root;
        }
        else if(!right || !left){
            return !left? right:left;
        }
        else{
            return nullptr;
        }
    }
};