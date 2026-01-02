class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> threeSums;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++) {
            int x = nums[i];
            for (int j = i+1; j < nums.size()-1; j++) {
                int y = nums[j];
                if (binary_search(nums.begin()+j+1, nums.end(), 0-x-y)) {
                    int z = *lower_bound(nums.begin()+j+1, nums.end(), 0-x-y);
                    threeSums.insert(vector<int>{x, y, z});
                }
            }
        }
        vector<vector<int>> out;
        for (vector<int> tuple : threeSums) {
            out.push_back(tuple);
        }
        return out;
    }
};