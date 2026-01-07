class Solution {
    public int removeDuplicates(int[] nums) {
        boolean[] found = new boolean[202];
        found[201] = true;
        int newn = 0;
        for (int i = 0; i < nums.length; i++) {
            if (found[nums[i]+100]) {
                nums[i] = 201;
            } else {
                found[nums[i]+100] = true;
                if (newn != i) {
                    nums[newn] = nums[i];
                }
                newn++;
            }
        }
        return newn;
    }
}