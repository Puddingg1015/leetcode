class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long long int closest = 0x7FFFFFFF;
        if (nums.size() == 3) return nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++) {
            int x = nums[i];
            for (int j = i+1; j < nums.size()-1; j++) {
                int y = nums[j];
                // cout << i << ": " << x << "\t" << j << ": " << y << "\t";
                int z1 = (*lower_bound(nums.begin()+j+1, nums.end()-1, target-x-y));
                // cout << z1;
                if (abs(x+y+z1-target) < abs(closest-target)) closest = x+y+z1;
                // cout << " | ";
                int z2 = (*upper_bound(nums.rbegin(), nums.rend()-j-2, target-x-y, greater<int>()));
                // cout << z2;
                if (abs(x+y+z2-target) < abs(closest-target)) closest = x+y+z2;
                // cout << " LF " << (target - x - y) <<  "\t" << closest << endl;
            }
        }
        return (int) closest;
    }
};