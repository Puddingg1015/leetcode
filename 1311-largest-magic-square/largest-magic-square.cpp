#define fori(N) for (int i = 0; i < N; i++)
#define forj(M) for (int j = 0; j < M; j++)

class Solution {
public:
    int sum_matrix[52][52] = {{0}};
    vector<vector<int>> grid;
    int largestMagicSquare(vector<vector<int>>& _grid) {
        grid = _grid;
        fori(grid.size()) {
            forj(grid[i].size()) {
                sum_matrix[i+1][j+1] += grid[i][j] + sum_matrix[i][j+1] + sum_matrix[i+1][j] - sum_matrix[i][j];
            }
        }
        cout << grid.size() << " " << grid[0].size() << endl;
        // fori(grid.size()+1) {
        //     forj(grid[0].size()+1) {
        //         cout << sum_matrix[i][j] << " ";
        //     } cout << endl;
        // }
        for (int size = min(grid.size(), grid[0].size()); size > 0; size--) {
            fori(grid.size() - size + 1) {
                forj(grid[0].size() - size + 1) {
                    if (isMagicSquare(i, j, size)) {
                        return size;
                    }
                }
            }
        }

        return 1;
    }

    bool isMagicSquare(int row, int col, int size) {
        int sum = sum_matrix[row+1][col+size] - sum_matrix[row+1][col] - sum_matrix[row][col+size] + sum_matrix[row][col];
        // cout << row << " " << col << " size:" << size << " sum:" << sum << endl;
        // cout << sum_matrix[row+1][col+size] << " " << sum_matrix[row+1][col] << " " << sum_matrix[row][col+size] << " " << sum_matrix[row][col] << endl;
        fori(size) {
            if (sum != sum_matrix[row+1+i][col+size] - sum_matrix[row+1+i][col] - sum_matrix[row+i][col+size] + sum_matrix[row+i][col]) {
                return false;
            }
        }
        forj(size) {
            if (sum != sum_matrix[row+size][col+1+j] - sum_matrix[row][col+1+j] - sum_matrix[row+size][col+j] + sum_matrix[row][col+j]) {
                return false;
            }
        }
        int diag_sum = 0;
        int inv_diag_sum = 0;
        fori(size) {
            diag_sum += grid[row+i][col+i];
            inv_diag_sum += grid[row+size-i-1][col+i];
        }
        if (sum != diag_sum || sum != inv_diag_sum) return false;
        return true;

    }
};