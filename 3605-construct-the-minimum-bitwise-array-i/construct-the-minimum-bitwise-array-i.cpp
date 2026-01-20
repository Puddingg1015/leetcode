// funny problem

class Solution {
public:

    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            ans.push_back(-1);
            for (int potnext = 0; potnext <= num; potnext++) {
                if ((potnext|(potnext+1)) == num) {
                    ans[i] = potnext;
                    break;
                }
            }
        }
        return ans;
    }
};