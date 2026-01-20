// first try yahhh 
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int r;
        int last0 = -1;
        int max_len = 0;
        for (r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                l = last0 + 1;
                last0 = r;
            }
            max_len = max(max_len, r - l);
        }
        return max_len;
    }
};