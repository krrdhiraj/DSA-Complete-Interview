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
    public ListNode middleNode(ListNode head) {
        ListNode slow = head;
        int n = 0;
        while(slow != null){
            n++;
            slow = slow.next;
        }
        int i = 0;
        ListNode tmp = head;
        while(i < n/2){
            tmp = tmp.next;
            i++;
        }
        return tmp;
    }
}