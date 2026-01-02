class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long int out = 0;
        for (int i = 0; i < k; i++) {
            int cur = happiness.back();
            if (cur-i <= 0) break;
            out += cur-i;
            happiness.pop_back();
        }
        return out;
    }
};