#include<bits/stdc++.h>
#define fori(N) for (int i = 0; i < N; i++)
#define forj(M) for (int j = 0; j < M; j++)

using namespace std;

class Solution {
public:
    vector<vector<int>> grid;
    int numMagicSquaresInside(vector<vector<int>>& grid1) {
        int count = 0;
        grid = grid1;
        fori((int)grid.size()-2) {
            forj((int)grid[i].size()-2) {
                if (isProperMagicSquare(i, j)) {
                    count++;
                    cout << i << " " << j << endl;
                }
            }
        }
        return count;
    }

    bool isProperMagicSquare(int row, int col) {
        if (potMagicSquare(row, col)) {
            unordered_set<int> numbers;
            fori(3) {
                forj(3) {
                    int n = grid[row+i][col+j];
                    if (n > 9 || n < 1 || numbers.find(n) != numbers.end()) return false;
                    else numbers.insert(n);
                }
            }
            return true;
        }
        return false;
    }
    
    bool potMagicSquare(int row, int col) {
        try {
            int sum = grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2];
            fori(3) {
                if (grid[row+i][col] + grid[row+i][col+1] + grid[row+i][col+2] != sum) {
                    return false;
                }
                if (grid[row][col+i] + grid[row+1][col+i] + grid[row+2][col+i] != sum) {
                    return false;
                } 
            }
            return (sum == grid[row+2][col] + grid[row+1][col+1] + grid[row][col+2]);
        } catch (exception e) {
            return false;
        }
    }
};