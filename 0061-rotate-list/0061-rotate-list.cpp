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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* start = head;
        int cnt = 0;
        while(start){
            cnt++;
            start = start->next;
        }
        k = k%cnt;
        while(k){
            ListNode* temp = head;
            ListNode* prev  = NULL;
            while(temp->next != NULL){
                cnt++;
                prev = temp;
                temp = temp->next;
            }
            ListNode* newNode = new ListNode(temp->val);
            newNode->next = head;
            prev->next = NULL;
            head = newNode;
            delete temp;
            k -= 1;
        }
        return head;
    }
};