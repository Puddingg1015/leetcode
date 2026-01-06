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
    public ListNode swapPairs(ListNode head) {
        int count = 0;
        ListNode out = new ListNode(0);
        ListNode curr = out;
        while (head != null) {
            count++;
            if (count % 2 == 1 && head.next != null) {
                ListNode dummy = head;
                ListNode dummy2 = head.next.next;
                head = head.next;
                head.next = dummy;
                head.next.next = dummy2;
            }
            curr.next = head;
            System.out.println(curr.val);
            curr = curr.next;
            head = head.next;
        }
        return out.next;
    }
}