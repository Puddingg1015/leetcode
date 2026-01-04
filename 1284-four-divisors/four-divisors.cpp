class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;        
        for (int num : nums) {
            vector<int> num_divisors = divisors(num);
            if (num_divisors.size() == 4) for (int divisor : num_divisors) sum += divisor;
        }
        return sum;
    }

    vector<int> divisors(int n) { 
        vector<int> out;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) out.push_back(i);
            if (out.size() > 4) break;
        }
        return out;
    }
};