class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto ap = lower_bound(nums.begin(), nums.end(), target);
        auto bp = upper_bound(nums.begin(), nums.end(), target);
        bool has = binary_search(nums.begin(), nums.end(), target);
        if (!has) return {-1, -1};
        return {(int) (ap - nums.begin()), (int) (bp - nums.begin() - 1)};
    }
};