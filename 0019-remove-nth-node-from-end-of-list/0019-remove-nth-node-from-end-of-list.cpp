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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr && head->next == nullptr){
        

        }
        ListNode* start = head;
        int cnt = 0;

        while(start != nullptr){
            cnt++;
            start = start->next;
        }
        int rem = cnt-n;
        if(rem == 0){
            return head->next;
        }
        start = head;
        while(rem > 1 && start != nullptr){
            start = start->next;
            rem--;
        }
        if(start->next == nullptr)
            start = nullptr;
        else{
            start->next = start->next->next;
        }
        return head;
    }
};