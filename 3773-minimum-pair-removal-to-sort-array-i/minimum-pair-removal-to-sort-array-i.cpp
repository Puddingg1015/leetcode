class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        bool non_decreasing;
        int count = 0;
        do {
            non_decreasing = true;
            int min_i = n-1;
            for (int i = n-1; i > 0; i--) {
                cout << nums[i] << " " << non_decreasing << endl;
                if (nums[i-1] > nums[i]) non_decreasing = false;
                if (nums[i] + nums[i-1] <= nums[min_i] + nums[min_i - 1]) min_i = i;
            }
            if (non_decreasing) break;
            nums[min_i] = nums[min_i] + nums[min_i-1];
            nums.erase(nums.begin() + min_i-1);
            n--;
            count++;
        } while (!non_decreasing);
        return count;
    }
};