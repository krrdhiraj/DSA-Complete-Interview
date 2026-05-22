/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/

class Solution {
    Node curr ;
    public void dfs(Node head){
        if(head == null)
            return ;
        Node temp = new Node(head.val);
        curr.next = temp;
        temp.prev = curr;
        curr = temp;
        if(head.child != null){
            dfs(head.child);
        }
        dfs(head.next);
    }
    public Node flatten(Node head) {
        Node dummy = new Node(0);
        curr = dummy;

        dfs(head);

        if(dummy.next != null)
            dummy.next.prev = null;

        return dummy.next;
    }
}