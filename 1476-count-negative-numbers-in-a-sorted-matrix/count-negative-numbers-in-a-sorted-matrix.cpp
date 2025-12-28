class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = grid.size()-1; i >= 0; i--) {
            for (int j = grid.at(i).size() - 1; j >=0; j--) {
                if (grid.at(i).at(j) >= 0) {
                    break;
                } else {
                    count++;
                }
            }
        }
        return count;
    }
};