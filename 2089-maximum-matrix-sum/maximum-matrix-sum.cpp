#define lng long long int

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // theory: given any number of operations you can reduce the number of negatives to 1 or 0
        int negatives = 0;
        lng sum = 0;
        int min_val = 100001;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int ele = matrix[i][j];
                if (ele < 0) {
                    negatives++;
                    if (-ele < min_val) min_val = -ele;
                    sum += -ele;
                } else {
                    if (ele < min_val) min_val = ele;
                    sum += ele;
                }
            }
        }
        if (!(negatives%2)) return sum;
        else return sum - 2*min_val;
    }
};