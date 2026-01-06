/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int[] sums = new int[10001];
    int maxLevel = 0;
    public int maxLevelSum(TreeNode root) {
        this.computeSum(1, root);
        int max = -0x7ffffff;
        int maxi = -1;
        for (int i = 1; i <= this.maxLevel; i++) {
            if (sums[i] > max) {
                max = sums[i];
                maxi = i;
            }
        }
        return maxi;
    }

    public void computeSum(int n, TreeNode node) {
        if (node == null) return;
        sums[n] += node.val;
        if (n > this.maxLevel) this.maxLevel = n;
        this.computeSum(n+1, node.left);
        this.computeSum(n+1, node.right);
    }
}