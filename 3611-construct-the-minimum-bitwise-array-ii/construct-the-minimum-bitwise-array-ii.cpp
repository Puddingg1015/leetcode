#define fori(N) for (int i = 0; i < N; i++)

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> out;
        fori(nums.size()) {
            int num = nums[i];
            out.push_back(-1);
            if (!(num % 2)) continue;
            int d = 1;
            while ((out[i] & d) != 0) {
                out[i] = num - d;
                d <<= 1;
            }
        }
        return out;
    }
};