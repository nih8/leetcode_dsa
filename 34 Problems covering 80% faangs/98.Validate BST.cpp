#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    bool valid(TreeNode* root,long long minn,long long maxx){
        if(!root)return true;
        if(root->left){
        if(root->left->val>=root->val){  //this check is unnecessary 
            return false;
        }
        if(root->left->val<=minn || root->left->val>=maxx){
            return false;
        }}
        if(root->right){
        if(root->right->val<=root->val){ //this check is unnecessary
            return false;
        }
        else if(root->right->val<=minn || root->right->val>=maxx){
            return false;
        }}
        
        return valid(root->left,minn,root->val)&& valid(root->right,root->val,maxx);

    }
    bool isValidBST(TreeNode* root) {
        return valid(root,LLONG_MIN,LLONG_MAX);
        //use of long max instead of int because int max and min values are included in the tree node values.
    }


    
    
};
//including this soln because its shorter and cooler :)
class gptSolution {
public:
    bool valid(TreeNode* root, long long minn, long long maxx){
        if(!root) return true;

        if(root->val <= minn || root->val >= maxx)
            return false;

        return valid(root->left, minn, root->val) &&
               valid(root->right, root->val, maxx);
    }

    bool isValidBST(TreeNode* root) {
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};
