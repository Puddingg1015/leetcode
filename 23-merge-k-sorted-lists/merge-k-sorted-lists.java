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
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode head = new ListNode(0);
        Comparator<ListNode> comp = new NodeComparator();
        PriorityQueue<ListNode> pq = new PriorityQueue<ListNode>(comp);
        for (int i = 0; i < lists.length; i++) {
            ListNode node = lists[i];
            if (node == null) continue;
            while (node != null) {
                // System.out.println(node.val);
                pq.add(node);
                node = node.next;
            }
        }
        ListNode curr = head;
        while (!pq.isEmpty()) {
            curr.next = pq.remove();
            curr = curr.next;
            // System.out.println(curr.val + " ");
            // System.out.println(curr.next);
        }
        head = head.next;
        return head;
    }
}

class NodeComparator implements Comparator<ListNode> {
    @Override
    public int compare(ListNode x, ListNode y) {
        if (x.val > y.val || x.val == y.val && x.next == null) return 1;
        return -1;
    }
}