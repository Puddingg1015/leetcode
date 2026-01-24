class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<pair<int, int>> pairs;
        int out = 0;
        for (int i = 0; i < n/2; i++) {
            pairs.push_back(make_pair(nums[i], nums[n-1-i]));
            out = max(out, nums[i] + nums[n-1-i]);
        }
        return out;
    }
};