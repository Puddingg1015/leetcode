#define NMAX 301

class Solution {
public:
    int dp[NMAX][NMAX] = {{0}};
    int countSquares(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) dp[i][0] = matrix[i][0];
        for (int i = 0; i < matrix[0].size(); i++) dp[0][i] = matrix[0][i];
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (!i || !j) continue;
                else if (matrix[i][j] == 0) dp[i][j] = 0;
                else {
                    matrix[i][j] = min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1])) + 1;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                // cout << matrix[i][j] << " ";
                    sum += matrix[i][j];
                } 
                // cout << endl;
        }
        return sum;
    }
};