#include<bits/stdc++.h>
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
       vector<int> v1 = search_tree_mid(root1);
       vector<int> v2 = search_tree_mid(root2); 
       vector<int> res;
       int pos1 = 0,pos2 = 0;
       while(pos1!=v1.size() || pos2!=v2.size()){
           if(pos1 != v1.size() && pos2 != v2.size()){
                if(v1[pos1] < v2[pos2]){
                    res.push_back(v1[pos1]);
                    pos1++;
                }else{
                    res.push_back(v2[pos2]);
                    pos2++;
                }
           }else if(pos1 != v1.size()){
               while(pos1 != v1.size()){
                   res.push_back(v1[pos1]);
                   pos1++;
               }
           }else if(pos2 != v2.size()){
               while(pos2 != v2.size()){
                   res.push_back(v2[pos2]);
                   pos2++;
               }
           }    
       }
       return res;
    }

    vector<int> search_tree_mid(TreeNode *root){
        stack<TreeNode*> stk;
        if(root != nullptr) stk.push(root);
        vector<int> result;
        if(root != nullptr){
            int flag = 1;
            while(flag || !stk.empty()){
                if(root->left != nullptr){
                    stk.push(root);
                    root = root -> left;
                }else if(root->right != nullptr){
                    stk.push(root);
                    root = root -> right;
                }else{
                    result.push_back(root->val);
                    root = stk.top();
                    stk.pop();
                    if(root->right == nullptr){
                        root = stk.top();
                        stk.pop();
                    }else{
                        root = root -> right;
                    }
                }
                flag = 0;
            }
        }
        return result;
    }

};
int main(){

system("pause");
return 0;
}