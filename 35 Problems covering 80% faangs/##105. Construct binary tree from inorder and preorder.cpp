#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
private:
    TreeNode*build(vector<int>&preorder,int start,int end){
        if(start>end) return nullptr;
        int rootval = preorder[preidx++];
        TreeNode* root = new TreeNode(rootval);
        int mid = m[rootval];
        root->left = build(preorder,start,mid-1);
        root->right = build(preorder,mid+1,end);
        return root;
    }
public:
    int preidx;
    unordered_map<int,int>m;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<preorder.size();i++){
            m[inorder[i]]=i;
        }
        preidx =0;
        return build(preorder,0,inorder.size()-1);


    }
};