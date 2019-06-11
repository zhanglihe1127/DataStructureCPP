#ifndef TREE_HPP
#define TREE_HPP
#include<vector>





struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):
        data(x), left(NULL), right(NULL) {}
};


class Solution{

public:
    // get the deepth of tree
    int getTreeDepthRecursive(TreeNode *pRoot){} 
      
    void binaryTreeMirrorRecursive(TreeNode *pRoot){}

    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int>vin){}

    void preOrder(TreeNode* pRoot){}
    void InOrder(TreeNode* pRoot){}
    void PostOrder(TreeNode* pRoot){}


};









#endif TREE_HPP