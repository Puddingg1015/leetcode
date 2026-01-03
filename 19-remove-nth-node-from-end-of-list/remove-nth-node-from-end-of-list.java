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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int k = 0;
        ListNode target = null;
        ListNode curr = head;
        while (curr != null) { 
            if (k-n == 0) target = head;
            if (k-n > 0) target = target.next;
            curr = curr.next;
            k++;
            // try {
            //     System.out.println(curr.val + " " + target + " " + k);
            // } catch (Exception _) {};
        }
        if (target == null) {
            return head.next;
        }
        if (target.next == null) {
            return null;
        }
        target.next = target.next.next;
        return head;
    }
}