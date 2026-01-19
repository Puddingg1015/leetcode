#define fori(N) for (int i = 0; i < N; i++)
#define forj(M) for (int j = 0; j < M; j++)

class Solution {
public:

    int sum_mat[301][301] = {{0}};
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        cout << n << " " << m << endl;
        fori(n) {
            forj(m) {
                sum_mat[i+1][j+1] = mat[i][j] + sum_mat[i+1][j] + sum_mat[i][j+1] - sum_mat[i][j];
                // cout << sum_mat[i+1][j+1] << "\t";
            } 
            // cout << endl;
        }
        for (int side = min(n, m); side > 0; side--) {
            fori(n - side + 1) {
                forj(m - side + 1) {
                    int pref_sum = getSum(i, j, side);
                    // if (side < 11) {cout << i << " " << j <<  " side:" << side << " sum:" << pref_sum << endl;
                    // cout << sum_mat[i+side][j+side] << "-" << sum_mat[i][j+1] << "-" << sum_mat[i+1][j] << "+" << sum_mat[i][j] << endl;
                    // }
                    if (pref_sum <= threshold && pref_sum >= 0) {
                        return side;
                    }
                }
            }
        }
        return 0;
    }

    int getSum(int row, int col, int side) {
        return sum_mat[row+side][col+side] - sum_mat[row][col+side] - sum_mat[row+side][col] + sum_mat[row][col];
    }
};