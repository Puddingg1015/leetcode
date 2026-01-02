#include <bits/stdc++.h>
#define lng long long int

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // this question kinda goofy
        vector<vector<int>> out;
        if (nums.size() < 4) {
            return out;
        }
        set<vector<int>> sets;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-3; i++) {
            lng w = nums[i];
            for (int j = i+1; j < nums.size()-2; j++) {
                lng x = nums[j];
                for (int k = j+1; k < nums.size()-1; k++) {
                    lng y = nums[k];
                    lng potz = (lng)target-w-x-y;
                    if (binary_search(nums.begin()+k+1, nums.end(), potz)) {
                        sets.insert(vector<int>{(int)w,(int)x,(int)y,(int)potz});
                    }
                }
            }
        }
        for (vector<int> quadruple : sets) out.push_back(quadruple);
        return out;
    }
};