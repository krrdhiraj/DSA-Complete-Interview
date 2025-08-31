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
       ListNode* s1 = headA;
        int len1 = 0, len2 = 0;
       while(s1 != nullptr){
            len1++;
            s1 = s1->next;
       }
        ListNode* s2 = headB;
       while(s2 != nullptr){
            len2++;
            s2 = s2->next;
       }
       s1 = headA, s2 = headB;
       if(len1 > len2){
          int diff = len1-len2;
          while(diff-- && s1 != nullptr){
            s1 = s1->next;
          }
       }else{
        int diff= len2-len1;
        while(diff-- && s2 != nullptr){
            s2 = s2->next;
        }
       }

       while(s1 != nullptr && s2 != nullptr){
         if(s1 == s2)
            return s1;
         s1 = s1->next;
         s2 = s2->next;
       }
       return nullptr;
    }
};