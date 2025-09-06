/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public void insertInBetween(Node head){
        Node temp = head;
        while(temp != null){
            Node copy = new Node(temp.val);
            copy.next = temp.next;
            temp.next = copy;
            temp = temp.next.next;
        }
    }
    public void connectRandomNode(Node head){
        Node temp = head;
        while(temp != null){
            Node copy = temp.next;
            if(temp.random != null)
                copy.random = temp.random.next;
            else
                copy.random = null;
            temp = temp.next.next;
        }
    }
    public Node extractCopiedList(Node head){
        Node temp = head;
        Node dummy = new Node(-1);
        Node curr = dummy;

        while(temp != null){
            curr.next = temp.next;
            curr = curr.next;

            temp.next = temp.next.next;
            temp = temp.next;
        }
        return dummy.next;
    }
    public Node copyRandomList(Node head) {
       insertInBetween(head);
       connectRandomNode(head);
       return extractCopiedList(head);
    }
}