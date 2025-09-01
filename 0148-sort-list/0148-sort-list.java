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
    public ListNode sortList(ListNode head) {
        List<Integer> list = new ArrayList<>();
        ListNode start = head;
        while(start != null){
            list.add(start.val);
            start = start.next;
        }
        Collections.sort(list);
         head = new ListNode(0);
         start = head;
        for(int val : list){
            start.next = new ListNode(val);
            start = start.next;
        }
        return head.next;
    }
}