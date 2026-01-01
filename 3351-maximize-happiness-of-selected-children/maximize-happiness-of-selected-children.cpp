class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long int out = 0;
        for (int i = 0; i < k; i++) {
            out += max(happiness.back()-(i), 0);
            happiness.pop_back();
        }
        return out;
    }
};