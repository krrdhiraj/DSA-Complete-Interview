/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertCopyInBetween(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }
    }
    void connectRandomPointer(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* copy = temp->next;
            if(temp->random){
                copy->random = temp->random->next;
            }else{
                copy->random = NULL;
            }
            temp = temp->next->next;
        }
    }
    Node* extractNewList(Node* head){
        Node* dummy = new Node(-1);
        Node* curr = head;
        Node* temp = dummy;

        while(curr != NULL){
            temp->next = curr->next;
            temp = temp->next;

            curr->next = curr->next->next;
            curr = curr->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        insertCopyInBetween(head);
        connectRandomPointer(head);
       return extractNewList(head);
    }
};