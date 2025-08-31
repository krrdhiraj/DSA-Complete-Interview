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
       unordered_map<ListNode*, int> mp;
       
       while(s1 != nullptr){
            mp[s1] = 1;
            s1 = s1->next;
       }
        ListNode* s2 = headB;
       while(s2 != nullptr){
            if(mp.find(s2) != mp.end()){
                return s2;
            }
            s2 = s2->next;
       }
       return nullptr;
    }
};