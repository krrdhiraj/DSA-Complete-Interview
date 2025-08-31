/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* s1 = headA , *s2 = headB;
        
       while(s1 != s2){
            s1 = s1->next;
            s2 = s2->next;
            if(s1 == s2)
                return s1;
            if(s1 == nullptr)
                s1 = headB;
            if(s2 == nullptr)
                s2 = headA;
       }
       return s1;
    }
};