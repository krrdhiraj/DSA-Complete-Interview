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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head, *prev = nullptr;
        while(curr  != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr=temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* curr = head, *slow = head, *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = reverse(slow);

        while(temp->next != NULL){
            ListNode* nxt = curr->next;
            ListNode* t = temp;
            temp = temp->next;
            curr->next = t;
            curr->next->next = nxt;
            curr = nxt;
        }
    }
};