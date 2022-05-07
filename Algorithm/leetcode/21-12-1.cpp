//leetcode 链表两数相加
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
        ListNode *p = new ListNode();
        ListNode *head = p;
        int sum = l1->val + l2->val;
        int carry = 0; 
        if(sum>9){
            carry = 1;
            sum %= 10;
        }
        p->val = sum;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 != nullptr||l2 != nullptr){
            ListNode *n = new ListNode();
            p->next = n;
            p = n;
            if(l1 != nullptr && l2 != nullptr){
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 != nullptr){
                sum = l1->val + carry;
                l1 = l1->next;
            }
            else if(l2 != nullptr){
                sum = l2->val + carry;
                l2 = l2->next;
            }
            carry = 0;
            if(sum>9){
            carry = 1;
            sum %= 10;
            }
            p->val = sum;
        }
        if(carry){
            ListNode *n = new ListNode();
            p->next = n;
            n->val = 1;
        }
        return head;
    }
};