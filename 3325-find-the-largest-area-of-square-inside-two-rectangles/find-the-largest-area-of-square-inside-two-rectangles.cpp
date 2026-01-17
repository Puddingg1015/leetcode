#define fori(N) for (int i = 0; i < N; i++)
#define forj(M) for (int j = 0; j < M; j++)
#define lng long long int

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        // vector<vector<int>> inter_bl;
        // vector<vector<int>> inter_tr;
        lng max_side = 0;
        fori(n-1) {
            for (int j = i+1; j < n; j++) {
                // cout << i << " " << j << endl;
                // if (i <= j) continue;
                if (bottomLeft[i][0] >= topRight[j][0] || bottomLeft[i][1] >= topRight[j][1] || 
                        bottomLeft[j][0] >= topRight[i][0] || bottomLeft[j][1] >= topRight[i][1]) continue;
                // if (topRight[i][0] >= bottomLeft[j][0] && topRight[i][1] >= bottomLeft[j][1]) {
                //     inter_bl.push_back(bottomLeft[j]);
                //     inter_tr.push_back(topRight[i]);
                int bl_x = max(bottomLeft[i][0], bottomLeft[j][0]);
                int bl_y = max(bottomLeft[i][1], bottomLeft[j][1]);
                int tr_x = min(topRight[i][0], topRight[j][0]);
                int tr_y = min(topRight[i][1], topRight[j][1]);
                // inter_bl.push_back(vector<int>{max(bottomLeft[i][0], bottomLeft[j][0]), max(bottomLeft[i][1], bottomLeft[j][1])});
                // inter_tr.push_back(vector<int>{min(topRight[i][0], topRight[j][0]), min(topRight[i][1], topRight[j][1])});
                max_side = max(max_side, (lng)min(tr_x - bl_x, tr_y - bl_y));
            }
        }
        // fori(inter_bl.size()) {
        //     // cout << inter_bl[i][0] << "," << inter_bl[i][1] << "  " << inter_tr[i][0] << "," << inter_tr[i][1] << endl;
        //     max_side = max(max_side, (lng) min(inter_tr[i][0] - inter_bl[i][0], inter_tr[i][1] - inter_bl[i][1]));
        // }
        return max_side * max_side;
    }
};