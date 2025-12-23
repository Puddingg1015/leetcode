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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        boolean addOne = false;
        ListNode out = null;
        ListNode last = null;
        while (l1 != null || l2 != null) {
            int digit = ((l1 == null ? 0 : l1.val) + (l2 == null ? 0 : l2.val));
            ListNode current = new ListNode(digit + (addOne ? 1 : 0));
            if (current.val >= 10) {
                current.val -= 10;
                addOne = true;
            } else {
                addOne = false;
            }
            if (last != null) {
                last.next = current;
            } else {
                out = current;
            }
            last = current;
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
        }
        if (addOne) {
            last.next = new ListNode(1);
        }
        return out;
    }
}