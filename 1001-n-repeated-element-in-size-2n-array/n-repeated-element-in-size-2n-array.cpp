class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> unique_nums;
        for (int num : nums) {
            if (unique_nums.find(num) != unique_nums.end()) return num;
            unique_nums.insert(num);
        }
        return NULL;
    }
};