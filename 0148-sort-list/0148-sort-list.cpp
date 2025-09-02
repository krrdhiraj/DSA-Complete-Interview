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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeLL(ListNode* list1, ListNode* list2){
        ListNode* start = new ListNode(0);
        ListNode* temp = start;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if(list1 != nullptr)
            temp->next = list1;
        else
            temp->next = list2;
        return start->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* middle = findMiddle(head);
        ListNode* right  = middle->next;
        middle->next = nullptr;

        ListNode* left = head;
        left =  sortList(left);
        right = sortList(right);
        return mergeLL(left, right);
    }
};