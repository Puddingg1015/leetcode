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

    public long MMOD = 1000000007L;

    long[] sumsByLayer = new long[50002];
    HashMap<TreeNode, Long> sumsFromNode = new HashMap<TreeNode, Long>();
    int maxLayer = 0;
    TreeNode root = new TreeNode(-1);
    long totalSum;

    public int maxProduct(TreeNode root) {
        this.root = root;
        this.totalSum = sumTree(root, 0);
        return (int)(solve(root, 0, 0) % MMOD);
    }

    public long solve(TreeNode node, long maxProd, int layer) {
        if (node == null) return maxProd;
        long leftProd = 0;
        long rightProd = 0;
        // long prevSum = 0;
        // if (layer >= 1) prevSum = sumTree(this.root, layer-1, 0);
        // System.out.println(node.val);
        // System.out.println(prevSum);
        if (node.left != null) {
            // long rest = sumTree(this.root, 0, layer, node, 'l');
            long left = sumTree(node.left, layer);
            leftProd = left*(this.totalSum - left);
            // System.out.println("L: " + left + " " + rest);
        }
        if (node.right != null) {
            // long rest = sumTree(this.root, 0, layer, node,'r');
            long right = sumTree(node.right, layer);
            rightProd = (this.totalSum - right) * right;
            // System.out.println("R: " + rest + " " + right);
        }
        if (leftProd > maxProd) maxProd = leftProd; 
        if (rightProd > maxProd) maxProd = rightProd; 
        // System.out.println("Left & Right Prod: " + leftProd + " " + rightProd + " " + this.root.val);
        return Math.max(solve(node.left, maxProd, layer + 1), solve(node.right, maxProd, layer + 1));
    }

    public long sumTree(TreeNode node, int layer) {
        if (this.sumsFromNode.containsKey(node)) return this.sumsFromNode.get(node);
        if (layer > this.maxLayer) this.maxLayer = layer;
        long sum = node.val;
        if (node.left != null) sum += sumTree(node.left, layer + 1);
        if (node.right != null) sum += sumTree(node.right, layer + 1);
        // if (this.sumsFromLayer[layer] == 0) this.sumsFromLayer[layer] = sum;
        // if (layer == 0) this.sumsByLayer[this.maxLayer] = sum;
        this.sumsFromNode.put(node, sum);
        return sum;
    }

    public long sumTree(TreeNode node, int endLayer, int curLayer) {
        long sum = node.val;
        if (endLayer <= curLayer) return sum;
        if (curLayer == 0 && this.sumsByLayer[endLayer] != 0) return this.sumsByLayer[endLayer]; 
        if (node.left != null) sum += sumTree(node.left, endLayer, curLayer + 1);
        if (node.right != null) sum += sumTree(node.right, endLayer, curLayer + 1);
        if (curLayer == 0 && this.sumsByLayer[endLayer] == 0) this.sumsByLayer[endLayer] = sum; 
        return sum;
    }

    public long sumTree(TreeNode node, int layer, int splitLayer, TreeNode splitNode, char ignoreNode) {
        // if (long sumTree(TreeNode node));
        // if (layer == 0 && splitLayer > 1) {
        //     return sumTree(splitNode, splitLayer, splitLayer, splitNode, ignoreNode) + this.sumsByLayer[splitLayer-1];
        // } 
        long sum = node.val;
        if (layer == splitLayer && node == splitNode) {
            if (ignoreNode == 'l') {
                if (node.right != null) sum += sumTree(node.right, layer); 
            } else if (ignoreNode == 'r') {
                if (node.left != null) sum += sumTree(node.left, layer);
            }
        } else {
            if (node.left != null) sum += sumTree(node.left, layer + 1, splitLayer, splitNode, ignoreNode);
            if (node.right != null) sum += sumTree(node.right, layer + 1, splitLayer, splitNode, ignoreNode);
        }
        return sum;
    }
}