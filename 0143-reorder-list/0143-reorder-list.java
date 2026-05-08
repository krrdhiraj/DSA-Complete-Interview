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
    public ListNode reverse(ListNode head){
        ListNode curr = head, prev = null;
        while(curr != null){
            ListNode temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    public void reorderList(ListNode head) {

        ListNode slow = head, fast = head, curr = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode reverseHead = reverse(slow);
        while( reverseHead.next != null){
            ListNode temp = curr.next;
            ListNode node = reverseHead;
            reverseHead = reverseHead.next;
            curr.next = node;
            curr.next.next = temp;
            curr = temp;
        }
    }
}