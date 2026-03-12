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
    int ans =INT_MIN;
    int help(TreeNode*root){
        if(!root){
            return 0;
        }
        int max1 = max(help(root->left),0);
        int max2 = max(help(root->right),0);
        int path = root->val + max1+max2;
        ans = max(ans,path);
        return root->val + max(max1,max2);
    }
    int maxPathSum(TreeNode* root) {
        help(root);
        return ans;
    }
};