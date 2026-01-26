class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int min_diff = INT_MAX;
        vector<int> indices;
        for (int i = 0; i < arr.size() - 1; i++) {
            int diff = arr[i+1] - arr[i];
            if (diff < min_diff) {
                min_diff = diff;
                indices.clear();
                indices.push_back(i);
            } else if (diff == min_diff) {
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