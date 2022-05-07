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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> tt;
        TreeNode* p = root;
        long long lastVal= INT64_MIN;
        while(!tt.empty() || p != NULL){
            if(p!=NULL){
                tt.push(p);
                p = p->left;
            }else{
                p = tt.top();
                if(lastVal > p->val) return false;
                tt.pop();
                p = p->right;
            }
        }
        return true;
    }
};

int main(){

system("pause");
return 0;
}