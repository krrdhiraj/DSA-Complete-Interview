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
    ListNode* findKthNode(ListNode* temp, int k){
        while(temp != NULL && k > 1){
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL, *curr = head;
        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* temp = head, *nextNode = NULL, *prevNode = NULL;
       while(temp != NULL){
            ListNode* kthNode = findKthNode(temp, k);
            if(kthNode == NULL){
                if(prevNode){
                    prevNode->next = temp;
                    break;
                }
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;
            reverse(temp);

            if(head == temp){
                head = kthNode;
            }else{
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
       }
       return head;
    }
};