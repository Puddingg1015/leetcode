#include<bits/stdc++.h>
#define fori(N) for (int i = 0; i < N; i++)
#define forj(M) for (int j = 0; j < M; j++)

using namespace std;

class Solution {
public:
    int cum_matrix[201][201] = {{0}};
    int max_rec[201][201] = {{0}}; // maximum rectangle up to [:i+1][:j+1]
    int maximalRectangle(vector<vector<char>>& matrix) {
        int out = 0;
        fori(matrix.size()) {
            forj(matrix[i].size()) {
                if (!i) {
                    cum_matrix[0][j] = matrix[0][j] - '0';
                    if (!j) if (cum_matrix[i][j]) max_rec[i][j] = 1;
                    continue;
                }
                cum_matrix[i][j] = (matrix[i][j] == '0' ? 0 : cum_matrix[i-1][j]+1);
            }
            int peak_j = 0;
            stack<int> prev_j;
            // sort(cum_matrix[i], cum_matrix[i]+(int)matrix[i].size(), greater<int>());
            forj(matrix[i].size()+1) {
                // cout << "here 1" << endl;
                if (!j) {
                    prev_j.push(j);
                    continue;
                }
                while (!prev_j.empty() && cum_matrix[i][j] <= cum_matrix[i][prev_j.top()]) {
                    peak_j = prev_j.top();
                    prev_j.pop();
                    int cur_area;
                    if (prev_j.empty()) cur_area = cum_matrix[i][peak_j]*(j);
                    else cur_area = cum_matrix[i][peak_j]*(min(j, (int)matrix[i].size())-prev_j.top()-1);
                    max_rec[i][j] = max(cur_area, max_rec[i][j]);
                    // else max_rec[i][j] = max(cur_area, max(max_rec[i][j-1], max_rec[i-1][j]));
                    // cout << "here 2" << " " << i << ' ' << j << ' ' << cur_area << ' ' << max_rec[i][j] << endl;
                }
                max_rec[i][j] = max(max_rec[i][j], max_rec[i][j-1]);
                prev_j.push(j);
            }
        }
        // fori(matrix.size()) {
        //     forj(matrix[i].size()+1) {
        //         cout << cum_matrix[i][j] << " ";
        //     } cout << endl;
        // }
        // cout << endl;
        // fori(matrix.size()) {
        //     forj(matrix[i].size()+1) {
        //         cout << max_rec[i][j] << " ";
        //     } cout << endl;
        // }
        fori(matrix.size()) {
            out = max(out, max_rec[i][matrix[0].size()]);
        }
        return out;
    }
};