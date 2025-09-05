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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> vec;
        ListNode* temp = head;
        while(temp != nullptr){
            vec.push_back(temp->val);
            temp = temp->next;
        }
        for(int i = 0; i+k<=vec.size(); i += k){
            int l = i, r = i+k-1;
            while(l < r){
                swap(vec[l], vec[r]);
                l++;r--;
            }
        }
        ListNode* dummy = new ListNode(-1);
        temp = dummy;
        for(int val : vec){
            temp->next = new ListNode(val);
            temp = temp->next;
        }
        return dummy->next;
    }
};