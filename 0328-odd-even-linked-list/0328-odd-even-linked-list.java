/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head == null || head.next == null || head.next.next == null){
            return head;
        }
       ListNode start  = head;
       ListNode odd = head, even = head.next;
       ListNode evenStart = head.next;

       while(even != null && even.next != null){
        odd.next = even.next;
        even.next = even.next.next;
        odd = odd.next;
        odd.next = evenStart;
        even = even.next;
       }
       return start;
    }
} 