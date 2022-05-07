#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> tt;
        TreeNode* p = root;
        while(!tt.empty() || p != NULL){
            if(p != NULL){
                tt.push(p);
                p = p->left;
            }else if(p == NULL){
                p = tt.top();
                res.push_back(tt.top()->val);
                tt.pop();
                p = p->right;
            }
        }
        return res;
    }
};
int main(){

system("pause");
return 0;
}
