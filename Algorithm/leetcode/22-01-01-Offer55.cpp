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
    int maxDepth(TreeNode* root) {
        if(root) return 0;
        else return max(maxDepth(root->left),maxDepth(root->right));
    }
};
int main(){

system("pause");
return 0;
}