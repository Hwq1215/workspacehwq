#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int res = 1000000;
        int rval =1000000,lval = 1000000;
        if(root == nullptr) return res;
        else if(root->left&&root->right){
            TreeNode *lNode = root->left;
            TreeNode *rNode = root->right;
            if(lNode != nullptr) while(lNode->right!=nullptr){lNode = lNode->right;}
            if(rNode != nullptr) while(rNode->left!=nullptr) {rNode = rNode->left;}
            res = min(abs(root->val - lNode->val),abs(root->val - rNode->val));
        }else if(root->left){
            TreeNode *lNode = root->left;
            if(lNode != nullptr) while(lNode->right!=nullptr){lNode = lNode->right;}
            res = abs(root->val - lNode->val);
        }else if(root->right){
            TreeNode *rNode = root->right;
            if(rNode != nullptr) while(rNode->left!=nullptr) {rNode = rNode->left;}
            res = abs(root->val - rNode->val);
        }
        return min(res,min(getMinimumDifference(root->left),getMinimumDifference(root->right)));
    }
};
int main(){

system("pause");
return 0;
}