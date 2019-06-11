/*
    reference: https://www.cnblogs.com/pangxiaodong/archive/2011/08/22/2149035.html
    reference: https://blog.csdn.net/qq_28869927/article/details/81104921 二叉树镜像(递归)
    reference: https://blog.csdn.net/yang20141109/article/details/50857648 二叉树镜像(递归和给递归)
    reference: https://blog.csdn.net/Ananbei/article/details/81639775 重建二叉树(递归，前序和中序)
*/
#include<iostream>
#include<Tree.hpp>
#include<algorithm>
#include<stack>

using namespace std;


int Solution::getTreeDepthRecursive(TreeNode *pRoot){
    if(!pRoot) 
        return 0;
    return max(getTreeDepthRecursive(pRoot->left)+1, getTreeDepthRecursive(pRoot->right)+1);
}

void Solution::binaryTreeMirrorRecursive(TreeNode *pRoot){
        if(NULL == pRoot){
            return;
        }
        if((NULL == pRoot->left) && (NULL == pRoot->right)){
            return;
        }
        TreeNode* pTemp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pTemp;

        if(pRoot->left){
            binaryTreeMirrorRecursive(pRoot->left);
        }
        if(pRoot->right){
            binaryTreeMirrorRecursive(pRoot->right);
        }
}

TreeNode* Solution::reConstructBinaryTree(vector<int>pre, vector<int>vin){
    int treeSize = pre.size();
    if(treeSize==0) return NULL;
    int mid_idx = 0;
    for(int i=0; i<treeSize; i++){
        if(pre[0]==vin[i]){
            mid_idx = i;
            break;
        }
    } 

    vector<int>preLeft, preRight, vinLeft, vinRight;
    for(int i=0; i<mid_idx; i++){
        preLeft.push_back(pre[i+1]);
        vinLeft.push_back(vin[i]);
    }
    for(int i=mid_idx+1; i<treeSize; i++){
        preRight.push_back(pre[i]);
        vinRight.push_back(vin[i]);
    }
    TreeNode* head = new TreeNode(pre[0]);

    head->left = reConstructBinaryTree(preLeft, vinLeft);
    head->right = reConstructBinaryTree(preRight, vinRight);
    return head;
}

void Solution::preOrder(TreeNode* pRoot){
    assert(NULL != pRoot);
    stack<TreeNode*> theStack;
    theStack.push(pRoot);
    while(!theStack.empty()){
        pRoot = theStack.top();
        cout << pRoot->data << " ";
        theStack.pop();

        if(pRoot->right)
            theStack.push(pRoot->right);
        if(pRoot->right)
            theStack.push(pRoot->right);
    }
}


void Solution::InOrder(TreeNode* pRoot){
    assert(NULL != pRoot);
    stack<TreeNode*> theStack;
    // theStack.push(pRoot);

    while(pRoot || !theStack.empty()){
        if(NULL != pRoot){
            theStack.push(pRoot);
            pRoot = pRoot->left;
        }else{
            cout << theStack.top()->data << " ";
            pRoot = theStack.top()->right;
            theStack.pop();
        }
    }
}

void Solution::PostOrder(TreeNode* pRoot){
    
    stack<TreeNode*> theStack;
    TreeNode* pre;
    while(pRoot || !theStack.empty()){
        if(NULL != pRoot){
            theStack.push(pRoot);
            pRoot = pRoot->left;
        }else{
            if(NULL != theStack.top()->right && theStack.top()->right != pre){
                // theStack.push(theStack.top()->right);
                // pRoot = theStack.top();
                // pRoot = theStack.top()->right;
                pRoot = pRoot->right;
            }else{
                cout << theStack.top()->data << " ";
                pre = theStack.top();
                theStack.pop();
            }
        }
    }

}



