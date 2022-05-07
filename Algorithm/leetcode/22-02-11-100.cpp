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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr&& q==nullptr) return true;
        else if(p==nullptr||q==nullptr) return false;
        stack<TreeNode*> pSt,qSt;
        pSt.push(p);
        qSt.push(q);
        p = p->left;
        q = q->left;
        while(!pSt.empty()&&!qSt.empty()){
            if((p==nullptr&&q!=nullptr)||(p!=nullptr&&q==nullptr)){
                return false;
            }else if(p==nullptr&&q==nullptr){
                p = pSt.top()->right;
                q = qSt.top()->right;
                pSt.pop();
                qSt.pop();
            }else{
                if(p->val!=q->val) return false;
                else{
                    pSt.push(p);
                    qSt.push(q);
                    p = p->left;
                    q = q->left;
                }
            }
        }
        return true;
    }
};
int main(){

system("pause");
return 0;
}