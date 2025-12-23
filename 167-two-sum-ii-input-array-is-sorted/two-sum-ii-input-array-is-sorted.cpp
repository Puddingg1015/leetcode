#include "bits/stdc++.h"

#define fori(NN) for (int i = 0; i < NN; i++)
#define ll long long int

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<ll, int> indices;
        map<ll, int> aux_indices;
        fori(n) {
            if (indices.find(nums[i]) == indices.end()) {
                indices[nums[i] + 0L] = i;
            } else {
                aux_indices[nums[i]] = i;
            }
        }
        fori(n) {
            ll x = nums[i];
            ll y = target - x;
            if (binary_search(nums.begin() + i, nums.end(), y)) {
                if (indices[x] == indices[y]) {
                    return vector<int>{indices[x]+1, aux_indices[y]+1};
                }
                return vector<int>{indices[x]+1, indices[y]+1};
            }
        }
        return vector<int>{-1, -1};
    }
};