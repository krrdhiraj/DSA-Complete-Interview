/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* s1 = l1 , *s2 = l2;
        int carry = 0;
        ListNode* temp = new ListNode(0);
        ListNode* p = temp;
        while(s1 != nullptr && s2 != nullptr){
            int val = s1->val + s2->val + carry;
            carry = val/10;
            ListNode *newNd = new ListNode(val%10);
            p->next = newNd;
            p  = p->next;
            s1 = s1->next;
            s2 = s2->next;
        }
        while(s1 != NULL){
            int val = s1->val+carry;
            carry = val/10;
            ListNode *newNd = new ListNode(val%10);
            p->next = newNd;
            p  = p->next;
            s1 = s1->next;
        }
        while(s2 != NULL){
            int val = s2->val + carry;
            carry = val/10;
            ListNode *newNd = new ListNode(val % 10);
            p->next = newNd;
            p  = p->next;
            s2 = s2->next;
        }
        if(carry > 0){
            ListNode *newNd = new ListNode(carry);
            p->next = newNd;
            p = p->next;
        }
        return temp->next;
    }
};