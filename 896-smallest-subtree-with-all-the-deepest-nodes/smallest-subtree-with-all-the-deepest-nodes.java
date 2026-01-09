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
    public int maxDepth = 0;
    public int deepNodes = 0;
    public TreeNode deepestNode;
    public HashMap<TreeNode, Integer> subTreereeHeights = new HashMap<TreeNode, Integer>();
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        this.findMaxDepth(root, 0);
        Queue<Pair<TreeNode, Integer>> nodes = new LinkedList<Pair<TreeNode, Integer>>();
        nodes.add(new Pair<TreeNode, Integer>(root, 0));
        Queue<TreeNode> valids = new LinkedList<TreeNode>();
        if (this.deepNodes == 1) return this.deepestNode;
        while (!nodes.isEmpty()) {
            TreeNode node = nodes.peek().getKey();
            int depth = nodes.poll().getValue();
            if (node.left != null) nodes.add(new Pair<TreeNode, Integer>(node.left, depth+1));
            if (node.right != null) nodes.add(new Pair<TreeNode, Integer>(node.right, depth+1));
            if (node.left != null && node.right != null && this.getTreeHeight(node.left) == this.getTreeHeight(node.right) && this.getTreeHeight(node.left) == this.maxDepth - depth) {
                valids.add(node);
            } 
            // else if (node.left != null && this.getTreeHeight(node.left) == this.maxDepth - depth) {
            //     valids.add(node);
            // } else if (node.right != null && this.getTreeHeight(node.right) == this.maxDepth - depth) {
            //     valids.add(node);
            // }
        }
        return valids.peek();
    }

    public void findMaxDepth(TreeNode node, int depth) {
        if (depth > this.maxDepth) {
            this.maxDepth = depth;
            this.deepNodes = 1;
            this.deepestNode = node;
        } else if (depth == this.maxDepth) {
            this.deepNodes++;
            this.deepestNode = node;
        }
        if (node.left != null) findMaxDepth(node.left, depth+1);
        if (node.right != null) findMaxDepth(node.right, depth+1);
    }

    public int getTreeHeight(TreeNode node) {
        if (this.subTreereeHeights.containsKey(node)) return this.subTreereeHeights.get(node);
        int height = 1;
        int leftSubTreeHeight = 0;
        int rightSubTreeHeight = 0;
        if (node.left != null) leftSubTreeHeight = getTreeHeight(node.left);
        if (node.right != null) rightSubTreeHeight = getTreeHeight(node.right);
        height += Math.max(leftSubTreeHeight, rightSubTreeHeight);
        this.subTreereeHeights.put(node, height);
        return height;
    }
}