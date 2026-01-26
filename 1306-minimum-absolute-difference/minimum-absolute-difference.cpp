class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size(); 
        int min_diff = INT_MAX;
        vector<int> indices;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i+1] - arr[i] < min_diff) {
                min_diff = arr[i+1] - arr[i];
                indices.clear();
                indices.push_back(i);
            } else if (arr[i+1] - arr[i] == min_diff) {
                indices.push_back(i);
            }
        }
        vector<vector<int>> out;
        for (int i : indices) {
            out.push_back(vector<int>{arr[i], arr[i+1]});
        }
        return out;
    }
};